

#ifndef INHERITCLASS_HPP
#define INHERITCLASS_HPP

#include "BaseClass.hpp"

class InheritClass : public BaseClass
{
private:
    unsigned int int3 = 810;
    unsigned int int4 = 1145141919;

public:
    InheritClass();

    // virtual unsigned int getInt2() const;
    
    // Q1
    unsigned int getInt2() const;

    // Q2
    // virtual unsigned int getInt2() const;

    // Q3
    // unsigned int getInt2() const override;

    // Q4
    // virtual unsigned int getInt2Misspelled() const;

    // Q5
    // unsigned int getInt2Misspelled() const override;

    // Q6
    unsigned int getInt1() const;

    // Q7
    // virtual unsigned int getInt1() const;

    // Q8
    // unsigned int getInt1() const override;

    // Q9
    // virtual unsigned int getInt1Misspelled() const;

    // Q10
    // unsigned int getInt1Misspelled() const override;

};







#endif