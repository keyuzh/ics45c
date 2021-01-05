

#ifndef BASECLASS_HPP
#define BASECLASS_HPP

class BaseClass
{
private:

    unsigned int int1 = 114514;
    unsigned int int2 = 1919;

public:

    BaseClass();

    virtual ~BaseClass() = default;

    unsigned int getInt1() const;

    virtual unsigned int getInt2() const;

};

#endif