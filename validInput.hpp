/*********************************************************************
** Program name: lab4
** Author:       Rebekah Koon
** Date:         7/18/19
** Description:  Header file for validInput functions. One function
**               determines if an integer inputted by the user is 
**               valid, another determines if an input is a valid
**               double value, and the final function determines if
**               a string input is valid.
*********************************************************************/

#ifndef VALID_INPUT_HPP
#define VALID_INPUT_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <iomanip>

using std::atoi;
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::istringstream;
using std::noskipws;
using std::fixed;
using std::showpoint;
using std::setprecision;

int validInput(int, int);
double validInput(double, double);
string validInput();

#endif