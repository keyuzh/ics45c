// HashMap.cpp
// ICS45C Fall 2020 Project 3
// Name: Keyu Zhang
// ID: 19898090
// UCINetID: keyuz4

#include <string>
#include "HashMap.hpp"

namespace
{
    unsigned int defaultHash(const std::string& strToHash)
    {
        // polynomial hash function being used here as the default hash
        // function since we are taking upper and lower case, as well as other
        // ascii characters as input, p is chosen to be 53. The value of m is
        // 10^9 + 9, which is big enough for few collision, while staying below
        // the maximum value allow for unsigned int.
        unsigned int value = 0;
        int p = 53;
        int m = 1e9 + 9;
        int power = 1;

        for (int i = 0; i < strToHash.length(); i++)
        {
            value = (value + (strToHash[i] * power)) % m;
            power = (power * p) % m;
        }
        
        return value;
    }
}


// initialize using default hash function
HashMap::HashMap()
    : hashFunction{defaultHash},
    hashTable{new Node*[HashMap::INITIAL_BUCKET_COUNT]},
    numberPossible{HashMap::INITIAL_BUCKET_COUNT},
    numberStored{0}
{
    // make every bucket points to a nullptr
    initializeTable(HashMap::INITIAL_BUCKET_COUNT);
}


// initialize using a provided function
HashMap::HashMap(HashFunction hashFunction)
    : hashFunction{hashFunction}, 
    hashTable{new Node*[HashMap::INITIAL_BUCKET_COUNT]},
    numberPossible{HashMap::INITIAL_BUCKET_COUNT}, 
    numberStored{0}
{
    // make every bucket points to a nullptr
    initializeTable(HashMap::INITIAL_BUCKET_COUNT);
}


// copy constructor
HashMap::HashMap(const HashMap& hm)
    : hashFunction{hm.hashFunction}, hashTable{new Node*[hm.numberPossible]},
    numberPossible{hm.numberPossible}, numberStored{0}
{
    // initialize a new hashtable
    initializeTable(hm.numberPossible);
    // transfer values from old table
    mergeTable(hm.hashTable, hm.numberPossible);
}


// destructor
HashMap::~HashMap()
{
    // clear will delete all linked list
    clear();
    // then just delete the array
    delete[] hashTable;
}


// assignment constructor
HashMap& HashMap::operator=(const HashMap& hm)
{
    if (this != &hm)
    {
        // delete the original table
        clear();
        delete[] hashTable;

        // copy member vaiables from the new object
        hashFunction = hm.hashFunction;
        hashTable = new Node*[hm.numberPossible];
        numberPossible = hm.numberPossible;
        numberStored = 0;

        // copy contents in the table
        initializeTable(hm.numberPossible);
        mergeTable(hm.hashTable, hm.numberPossible);
    }
    return *this;
}


void HashMap::add(const std::string& key, const std::string& value)
{
    // if key already exists do nothing
    if (contains(key))
    {
        return;
    }
    
    // get the index in hashTable to add
    unsigned int hashedValue = hashKey(key);

    if (hashTable[hashedValue] == nullptr)  // target bucket is empty
    {
        // make a new linked list
        hashTable[hashedValue] = new Node{key, value, nullptr};
    }
    else  // collision, add to end of existing linked list
    {
        Node* pointer = hashTable[hashedValue];

        while (pointer->next != nullptr)  // iterate to the end
        {
            pointer = pointer->next;
        }
        
        pointer->next = new Node{key, value, nullptr};  // add to the end
    }
    // increment the number of key/value pairs stored in the hashmap
    numberStored++;

    // check load factor to see if rehash is needed
    if (loadFactor() > HashMap::MAX_LOAD_FACTOR)
    {
        rehash();
    }
}


bool HashMap::remove(const std::string& key)
{
    // if the key is not in hashmap
    if (contains(key) == false)
    {
        return false;
    }
    // go to the correct bucket
    unsigned int hashedValue = hashKey(key);

    // if the first node is the one to remove
    if (hashTable[hashedValue]->key == key)
    {
        Node* toRemove = hashTable[hashedValue];  // store the node to delete

        // adjust pointer to point at the next node
        hashTable[hashedValue] = hashTable[hashedValue]->next;

        delete toRemove;  // delete the node
        numberStored--;   // one less pair stored in the table
        return true;
    }

    // else: go through the linked list and find the node
    Node* current = hashTable[hashedValue]->next;
    Node* prev = hashTable[hashedValue];

    while (current != nullptr)  // iterate through the linked list
    {
        if (current->key == key)  // found the matching key
        {
            Node* toRemove = current;  // make a pointer to the node to remove
            
            // adjust pointer in previous node
            prev->next = current->next;

            delete toRemove;  // delete node
            numberStored--;   // one less pair stored in the table
            return true;
        }
        // next node
        prev = current;
        current = current->next;
    }
    return false;  // did not find matching key
}


bool HashMap::contains(const std::string& key) const
{
    // go to the correct bucket
    Node* pointer = hashTable[hashKey(key)];

    // go through the linked list and check each key
    while (pointer != nullptr)
    {
        // check node->key
        if (pointer->key == key)  // found match
        {
            return true;
        }
        pointer = pointer->next;
    }
    return false;  // no match
}


std::string HashMap::value(const std::string& key) const
{
    // go to the correct bucket
    Node* pointer = hashTable[hashKey(key)];

    // go through the linked list and check each key
    while (pointer != nullptr)
    {
        // check node->key
        if (pointer->key == key)  // found match
        {
            return pointer->value;
        }
        pointer = pointer->next;
    }
    return "";  // no match, return empty string
}


unsigned int HashMap::size() const
{
    // number of pairs stored in hashmap
    return numberStored;
}


unsigned int HashMap::bucketCount() const
{
    // number of avaliable buckets(linked list)
    return numberPossible;
}


double HashMap::loadFactor() const
{
    return double(numberStored) / double(numberPossible);
}


unsigned int HashMap::maxBucketSize() const
{
    // find the maximum length of linked list in the hashmap
    unsigned int max = 0;

    // iterable through every bucket
    for (unsigned int i = 0; i < numberPossible; i++)
    {
        if (hashTable[i] != nullptr)  // there is a linked list at the bucket
        {
            unsigned int currentSize = 0;

            Node* pointer = hashTable[i];
            do  // iterate through the end of linked list
            {
                currentSize++;
                pointer = pointer->next;
            } while (pointer != nullptr);
            
            if (currentSize > max)  // if new maximum is found
            {
                max = currentSize;
            }
        }
    }
    return max;
}


unsigned int HashMap::hashKey(const std::string& key) const
{
    // find the right bucket for the given key
    return (hashFunction(key) % numberPossible);
}


void HashMap::initializeTable(unsigned int n)
{
    // make every cell in the array a nullptr
    for (unsigned int i = 0; i < n; i++)
    {
        hashTable[i] = nullptr;
    }
}


void HashMap::rehash()
{
    // increase the size of hashmap and rehash everything
    unsigned int oldSize = numberPossible;
    unsigned int newSize = (numberPossible * 2) + 1;

    Node** oldTable = hashTable;     // make a pointer to point to the old table
    hashTable = new Node*[newSize];  // make a new table of bigger size

    // set properties of new table
    numberPossible = newSize;
    numberStored = 0;
    initializeTable(newSize);

    // add contents from old table to new table, also delete all nodes
    mergeTable(oldTable, oldSize, true);
    delete[] oldTable;
}


void HashMap::mergeTable(
    Node** oldTable, const unsigned int size, bool removeOld
)
    // given a pointer to an hashTable, add all contents in that table
    // into the table of this class, if removeOld == true, then nodes
    // from old table will be deleted after adding to new table
{
    // loop through the old table and re-add everything
    for (unsigned int i = 0; i < size; i++)
    {
        if (oldTable[i] != nullptr)
        {
            // add the values to new array (then delete the old node if needed)
            Node* pointer = oldTable[i];

            while (pointer != nullptr)
            {
                add(pointer->key, pointer->value);

                Node* toRemove = pointer;
                pointer = pointer->next;

                if (removeOld == true)  // delete old node if needed
                {
                    delete toRemove;
                }
            }
        }
    }
}


void HashMap::clear()
{
    // delete all linked list stored in the hashmap
    for (unsigned int i = 0; i < numberPossible; i++)
    {
        if (hashTable[i] != nullptr)  // linked list found, now delete it
        {
            Node* pointer = hashTable[i];
            // iterate through the list and delete each node
            while (pointer != nullptr)
            {
                Node* toRemove = pointer;
                pointer = pointer->next;
                delete toRemove;
                numberStored--;
            }
            hashTable[i] = nullptr;  // restore the cell in array to be nullptr
        }
    }
}
