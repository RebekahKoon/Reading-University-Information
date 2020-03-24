/*********************************************************************
** Program name: lab4
** Author:       Rebekah Koon
** Date:         7/18/19
** Description:  Header file for the Person class, which keeps track
**               of information about people at a university. Has
**               functions to set and get the name and age of a 
**               person. Also has virtual functions to have a person
**               do work and to find the person's status (whether they
**               are a student or instructor).
*********************************************************************/

#ifndef PERSON_HPP
#define PERSON_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::endl;
using std::string;

//Used for identifying whether a person is a student or instructor
enum PersonStatus {STUDENT = 1, INSTRUCTOR = 2};

class Person
{
    protected:
        string name;
        int age;
    
    public:
        Person();
        Person(string, int);

        void setName(string);
        void setAge(int);

        string getName();
        int getAge();

        virtual void do_work();
        virtual PersonStatus findPersonStatus() = 0;

        virtual ~Person();
};

#endif