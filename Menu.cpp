/*********************************************************************
** Program name: lab4
** Author:       Rebekah Koon
** Date:         7/18/19
** Description:  Implementation file for the Menu class, which 
**               contains a function for printing the menu of options
**               a user can select from in finding out information
**               about the people and buildings of a university. Also 
**               contains a function for printing the names of the
**               people at the university.
*********************************************************************/

#include "Menu.hpp"


/*********************************************************************
** Description: Member function universityInfor prints the options a
**              user can choose from in finding out information about
**              a university or adding onto information about the
**              university. Returns the user's choice concerning what
**              action they would like to perform.
*********************************************************************/
int Menu::universityInfo()
{
    int choice;
    const int MIN_CHOICE = 1,
              MAX_CHOICE = 8;

    cout << endl << "Menu choices:" << endl;
    cout << "1. Prints information about all the buildings." << endl;
    cout << "2. Prints information of everybody at the university." << endl;
    cout << "3. Choose a person to do work." << endl;
    cout << "4. Add a new person." << endl;
    cout << "5. Add a building." << endl;
    cout << "6. Save information to a file." << endl;
    cout << "7. Read information from a file." << endl;
    cout << "8. Exit the program." << endl << endl;

    cout << "Enter your choice (1-8): ";

    choice = validInput(MIN_CHOICE, MAX_CHOICE);

    cout << endl;

    return choice;
}


/*********************************************************************
** Description: Member function doWorkMenu takes in a vector of 
**              pointers to Person objects as a parameter. Uses the
**              vector to print the names of the people in the vector.
**              Returns the person's name who will do work.
*********************************************************************/
string Menu::doWorkMenu(vector <Person *> people)
{
    string name;

    //Printing each person's name in the vector
    cout << "List of people at Oregon State University:" << endl;
    for (int i = 0; i < people.size(); i++)
    {
        cout << people[i]->getName() << endl;
    }

    cout << endl << "Enter the name of the person who will do work: ";
    name = validInput();

    return name;
}