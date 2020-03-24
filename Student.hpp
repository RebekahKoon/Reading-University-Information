/*********************************************************************
** Program name: lab4
** Author:       Rebekah Koon
** Date:         7/18/19
** Description:  Header file for the Student class, which is derived 
**               and inherits from the Person class. Has functions 
**               to set and get the GPA of a student, a function that
**               prints how much work a student does, and a function
**               to return the status of a student.
*********************************************************************/

#ifndef STUDENT_HPP
#define STUDENT_HPP

#include "Person.hpp"

#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

class Student: public Person
{
    private:
        double GPA;

    public:
        Student();
        Student(string, int, double);

        void setGPA(double);
        double getGPA();

        virtual void do_work();
        virtual PersonStatus findPersonStatus();

        ~Student();
};

#endif