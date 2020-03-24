/*********************************************************************
** Program name: lab4
** Author:       Rebekah Koon
** Date:         7/18/19
** Description:  Header file for the Menu class, which contains a
**               function for printing the menu of options a user
**               can select from in finding out information about the
**               people and buildings of a university. Also contains a
**               function for printing the names of the people at a
**               university.
*********************************************************************/

#ifndef MENU_HPP
#define MENU_HPP

#include "validInput.hpp"
#include "Person.hpp"
#include "Student.hpp"
#include "Instructor.hpp"

#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

class Menu
{
    public:
        int universityInfo();
        string doWorkMenu(vector <Person *>);
};

#endif