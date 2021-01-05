// Widget.hpp
//
// ICS 45C Fall 2020
// Code Example
//
// This is the declaration of a class called Widget, a class which offers two
// features:
//
// * Every Widget object has its own ID.  The IDs are presumably unique, though
//   nothing is done to explicitly enforce that.
// * At any given time, it's possible to determine how many Widget objects are
//   alive (i.e., have been allocated and not yet deallocated).
//
// The latter of these two features is implemented using a static member
// variable (to keep track of the count) and a static member function (to
// allow code outside of the Widget class to obtain the count without being
// able to change it).  The reason that these are static is that they are
// a feature of the class as a whole, as opposed to being a feature of each
// individual object of the class.

#ifndef WIDGET_HPP
#define WIDGET_HPP



class Widget
{
public:
    // We'll need a constructor, which initializes a Widget gives its ID.
    // We're assuming that some other part of the system generates these
    // IDs in some way that guarantees them to be unique.  The constructor
    // is explicit, since we don't want integers to be implicitly convertible
    // to Widget objects.
    explicit Widget(int id);

    // We'll also need a copy constructor and a destructor, not because
    // the member variables aren't well-behaved, but because these are
    // times when the widget count changes (i.e., whenever one is created,
    // even if it's a copy of an existing one, the widget count should
    // increase; whenever one is destroyed, the widget count should
    // decrease).
    //
    // Interestingly, we don't have an assignment operator here.  That's
    // because assigning one existing widget into another existing widget
    // doesn't change the count.  In every other way, the default
    // assignment operator would be fine, so we'll stick with that,
    // rather than implementing one by hand (and leaving ourselves open
    // to making a mistake).
    Widget(const Widget& w);
    ~Widget();

    // getId() returns the ID associated with the Widget you call it on.
    // (It's a non-static member function, which means you call it on a
    // particular Widget object.)
    int getId() const;

    // getWidgetCount() returns the number of Widget objects that currently
    // exist.  (It's a static member function, which means you call it
    // on the class, instead of on an individual object of that class.)
    //
    // Note, too, that I didn't write "const" on the end of the signature.
    // that's for good reason: There's no "this" object to protect here,
    // since static member functions are called on the class, as opposed
    // to objects of the class.
    static unsigned int getWidgetCount();

private:
    int id;

    // Member variables can be static, as well, if the goal is for there
    // to be a single one for the entire class.  That's sensible for the
    // widget count; there's only one such count, no matter how many
    // Widget objects you've created.  (And, in fact, there should be a
    // widget count even if there are *no* Widget objects.  Static
    // member variables of a class exist even if there are no objects of
    // that class.)
    static unsigned int widgetCount;
};



#endif // WIDGET_HPP

