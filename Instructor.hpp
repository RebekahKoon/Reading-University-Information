/*********************************************************************
** Program name: lab4
** Author:       Rebekah Koon
** Date:         7/18/19
** Description:  Header file for the Instructor class, which is
**               derived and inherits from the Person class. Has
**               functions to set and get an instructor's rating, a
**               function that prints how much work an instructor did,
**               and a function that returns the instructor's status.
*********************************************************************/

#ifndef INSTRUCTOR_HPP
#define INSTRUCTOR_HPP

#include "Person.hpp"

#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

class Instructor: public Person
{
    private:
        double rating;
    
    public:
        Instructor();
        Instructor(string, int, double);

        void setRating(double);
        double getRating();

        virtual void do_work();
        virtual PersonStatus findPersonStatus();

        ~Instructor();
};

#endif