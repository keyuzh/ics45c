void reverse(int* first, int* last)
{
    int numOfInterations = (last - first) / 2;

    int* pointBack = last;    // pointer to the int at the back of list
    int* pointFront = first;  // int at the front

    for (int i = 0; i < numOfInterations; ++i)
    {
        // swap the int at two pointers
        int temp = *pointBack;
        *pointBack = *pointFront;
        *pointFront = temp;

        pointFront++;  // front pointer go to next int
        pointBack--;   // back pointer go to prev int
    }
}