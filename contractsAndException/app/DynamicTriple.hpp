// DynamicTriple.hpp
//
// ICS 45C Fall 2020
// Code Example
//
// This header file declares and defines a class template called DynamicTriple,
// which implements the notion of a "triple" (i.e., a three-element tuple)
// whose elements, behind the scenes, are each allocated dynamically.  Not only
// does it endeavor to be correct in cases where everything works as it should,
// but it also makes its best effort to be exception safe.  Given the relative
// simplicity of its member functions, it is able to provide the "strong
// guarantee" in every case, because it can be provided at relatively low cost.
// (We're not always this lucky in practice, but simple problems often have
// very elegant solutions.)
//
// This example is a bit artificial, in the sense that there would be little
// need to build something like this on your own, without using a better tool
// like smart pointers that would obviate a lot of the exception handling
// we're doing here.  Still, this serves to illustrate some of the techniques
// you'd need to consider when trying to implement a data structure that is
// exception safe.  (It also serves as a case study of why the built-in smart
// pointer types can be useful; much of the complexity of what we're seeing
// here would melt away if we just used std::unique_ptrs in place of the raw
// pointers I'm using here, since the notion of ownership here is the same as
// what std::unique_ptr provides automatically.  In general, we can conclude
// that better tools are desperately needed to manage the complexity introduced
// by the possibility of exceptions being thrown in arbitrary places
// throughout our code.)

#ifndef DYNAMICTRIPLE_HPP
#define DYNAMICTRIPLE_HPP



// The DynamicTriple class template takes three type parameters, which
// specify the types of the three values that are stored in the triple.
// All a DynamicTriple does is store three values (one A, one B, and one
// C) in dynamically-allocated memory, while managing that memory so that
// the values are destroyed automatically when the DynamicTriple is
// destroyed.  It is also exception safe, as every member function
// provides either the "strong guarantee" or the "nothrow guarantee".

template <typename A, typename B, typename C>
class DynamicTriple
{
public:
    DynamicTriple();
    DynamicTriple(const A& a, const B& b, const C& c);
    DynamicTriple(const DynamicTriple& t);
    ~DynamicTriple();

    DynamicTriple& operator=(const DynamicTriple& t);

    A& a();
    const A& a() const;

    B& b();
    const B& b() const;

    C& c();
    const C& c() const;

    void clear();

private:
    A* pa;
    B* pb;
    C* pc;
};



// You'll notice in the implementations of the member functions that I'm
// frequently using a pattern that is sometimes called "catch-and-rethrow",
// in which we catch an exception (without caring what kind of exception
// it is), clean some things up, and then re-throw the exception.  This is
// a pattern you'll need when your goal isn't to handle an exception, but
// instead to be sure that certain things are cleaned up before an exception
// propagates out of the function.  This is particularly important when you
// need to do manual clean-up (such as manual deallocation of memory that
// was dynamically allocated).
//
// You'll also notice that there are no places here where I'm actually
// catching and handling an exception.  That's not an oversight, and that's
// not because I wanted DynamicTriple to be more brittle.  It's for the
// simple reason that there's nothing that DynamicTriple can do in the
// cases where exceptions are thrown *except* to be sure that it doesn't
// leak memory.  For example, in the default constructor, if there's no
// way to dynamically allocate the three values, there's no way for the
// constructor to succeed; what it *should* do in that case is simply
// fail, throwing an exception back to its caller.  Why are we so concerned
// with the possibility of failure?  Because there are two ways it can
// fail: (1) because one of the memory allocations fails with a std::bad_alloc
// (e.g., because there isn't enough available memory), or (2) because the
// default constructor of A, B, or C throws an exception of its own (and
// since this is a class template, we can't be sure that this is impossible,
// since we're not sure what A, B, and C are).



// This constructor (and several of the other member functions) is written
// more carefully than you might first realize.  A simpler approach would be
// to write this:
//
//    template <typename A, typename B, typename C>
//    DynamicTriple<A, B, C>::DynamicTriple()
//        : pa{new A}, pb{new B}, pc{new C}
//    {
//    }
//
// But the reason I didn't is because this would be incorrect in the case
// that one of the calls to "new" throws an exception.  In the case, for
// example, that "new C" throws an exception, the implementation above will
// leak memory, because a dynamically-allocated A and B will not be
// destroyed.  (When the DynamicTriple object dies because its constructor
// threw an exception, the pointers pa, pb, and pc will die, but the objects
// they point to will not.)
//
// To mitigate this problem, I did three things:
//
// (1) Initialize the pointers to nullptr
// (2) Attempt to allocate the three objects dynamically
// (3) Delete all of the objects if anything went wrong.  You might notice
//     that I passed pa, pb, and pc to "delete" without checking them, but
//     that's because C++ allows you to "delete" nullptr (it does nothing,
//     but is safe), and I've explicitly set all the pointers to nullptr
//     first.
//
// A similar pattern pervades throughout this example.

template <typename A, typename B, typename C>
DynamicTriple<A, B, C>::DynamicTriple()
    : pa{nullptr}, pb{nullptr}, pc{nullptr}
{
    try
    {
        pa = new A;
        pb = new B;
        pc = new C;
    }
    catch (...)
    {
        delete pc;
        delete pb;
        delete pa;
        throw;
    }
}


template <typename A, typename B, typename C>
DynamicTriple<A, B, C>::DynamicTriple(const A& a, const B& b, const C& c)
    : pa{nullptr}, pb{nullptr}, pc{nullptr}
{
    try
    {
        // Here, we construct the objects to be copies of the objects passed
        // as constructor parameters, but it's otherwise just like the default
        // constructor.

        pa = new A{a};
        pb = new B{b};
        pc = new C{c};
    }
    catch (...)
    {
        delete pc;
        delete pb;
        delete pa;
        throw;
    }
}


template <typename A, typename B, typename C>
DynamicTriple<A, B, C>::DynamicTriple(const DynamicTriple& t)
    : pa{nullptr}, pb{nullptr}, pc{nullptr}
{
    try
    {
        // Here, we construct the objects to be copies of the objects inside
        // the other DynamicTriple.

        pa = new A{*t.pa};
        pb = new B{*t.pb};
        pc = new C{*t.pc};
    }
    catch (...)
    {
        delete pc;
        delete pb;
        delete pa;
        throw;
    }
}


template <typename A, typename B, typename C>
DynamicTriple<A, B, C>::~DynamicTriple()
{
    // We know that pa, pb, and pc will always be pointing to legitimate
    // objects, since (a) it is impossible to have a DynamicTriple object
    // unless its constructor succeeded (and that success implies that pa,
    // pb, and pc are pointing to actual objects), and (b) no code outside
    // of DynamicTriple can manipulate (or even see) pa, pb, or pc.

    delete pc;
    delete pb;
    delete pa;
}


template <typename A, typename B, typename C>
DynamicTriple<A, B, C>& DynamicTriple<A, B, C>::operator=(const DynamicTriple& t)
{
    if (this != &t)
    {
        // There's some care being taken here.  To preserve the "strong
        // guarantee", we have to make sure that we don't start modifying
        // pa, pb, or pc until *after* all of the allocations -- the part
        // of this where there is a risk that exceptions will be thrown --
        // are complete.  If an exception is thrown, we destroy the things
        // we copied successfully and re-throw the exception.

        A* pcopya = nullptr;
        B* pcopyb = nullptr;
        C* pcopyc = nullptr;

        try
        {
            pcopya = new A{*t.pa};
            pcopyb = new B{*t.pb};
            pcopyc = new C{*t.pc};
        }
        catch (...)
        {
            delete pcopyc;
            delete pcopyb;
            delete pcopya;
            throw;
        }


        // Now that the allocations have succeeded, we can safely delete the
        // old objects and point to pa, pb, and pc to their replacements.
        // Nothing here can throw an exception (since we assume, reasonably,
        // that destructors do not throw).

        delete pa;
        pa = pcopya;

        delete pb;
        pb = pcopyb;

        delete pc;
        pc = pcopyc;
    }

    return *this;
}


template <typename A, typename B, typename C>
A& DynamicTriple<A, B, C>::a()
{
    return *pa;
}


template <typename A, typename B, typename C>
const A& DynamicTriple<A, B, C>::a() const
{
    return *pa;
}


template <typename A, typename B, typename C>
B& DynamicTriple<A, B, C>::b()
{
    return *pb;
}


template <typename A, typename B, typename C>
const B& DynamicTriple<A, B, C>::b() const
{
    return *pb;
}


template <typename A, typename B, typename C>
C& DynamicTriple<A, B, C>::c()
{
    return *pc;
}


template <typename A, typename B, typename C>
const C& DynamicTriple<A, B, C>::c() const
{
    return *pc;
}


template <typename A, typename B, typename C>
void DynamicTriple<A, B, C>::clear()
{
    // "Clearing" a DynamicTriple means to reset its values to be default-
    // constructed A, B, and C values.  As we do in the assignment operator,
    // though, we make sure that we can allocate the new default values
    // before we modify pa, pb, or pc.

    A* pcleara = nullptr;
    B* pclearb = nullptr;
    C* pclearc = nullptr;

    try
    {
        pcleara = new A;
        pclearb = new B;
        pclearc = new C;
    }
    catch (...)
    {
        delete pclearc;
        delete pclearb;
        delete pcleara;
        throw;
    }

    delete pa;
    pa = pcleara;

    delete pb;
    pb = pclearb;

    delete pc;
    pc = pclearc;
}



#endif // DYNAMICTRIPLE_HPP

