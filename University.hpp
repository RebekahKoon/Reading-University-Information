/*********************************************************************
** Program name: lab4
** Author:       Rebekah Koon
** Date:         7/18/19
** Description:  Header file for the University class, which has a
**               vector for people and a vector for buildings at a
**               university. Has functions for setting the name of the
**               university, setting the two vectors, taking in info
**               about people or buildings and then adding them as 
**               objects to the people or buildings vector, printing
**               info about the people or buildings, making a person
**               perform work, and reading or writing info to a file.
*********************************************************************/

#ifndef UNIVERSITY_HPP
#define UNIVERSITY_HPP

#include "Building.hpp"
#include "Person.hpp"
#include "Student.hpp"
#include "Instructor.hpp"
#include "Menu.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::fixed;
using std::showpoint;
using std::setprecision;
using std::ofstream;
using std::ifstream;
using std::transform;

class University
{
    protected:
        string universityName;

        vector <Person *> people;
        vector <Building *> buildings;
    
    public:
        University();
        University(vector <Person *>, vector <Building *>);

        void setUniversityName(string);
        void setPeopleVector(vector <Person *>);
        void setBuildingsVector(vector <Building *>);

        string getUniversityName();
        vector <Building *> getBuildingsVector();
        vector <Person *> getPeopleVector();

        void setPerson(Person *);
        void setBuilding(Building *);

        void addPerson();
        void addBuilding();

        void printBuildingInfo();
        void printPeopleInfo();
        void workPerson(string);

        void writeFile();
        void readFile();

        ~University();
};

#endif