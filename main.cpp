/**********************************************************************
** Program name: lab4
** Author:       Rebekah Koon
** Date:         7/18/19
** Description:  This program is used to store or read information
**               about people or buildings at Oregon State University.
**               A menu is printed for the user with options to print
**               building information, print information about people,
**               print how much work a person performs, add people or
**               a building to the information system, and read from
**               or write to a file. Uses the University, Person,
**               Student, and Instructor classes to handle information.
**               After the user is finished, exits the program.
**********************************************************************/

#include "Person.hpp"
#include "Student.hpp"
#include "Instructor.hpp"
#include "University.hpp"
#include "Menu.hpp"
#include "validInput.hpp"

#include <string>
#include <iostream>
#include <vector>

using std::string;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    int choice;

    string studentName = "Rebekah",
           instructorName = "John",
           buildingName1 = "Cordley Hall",
           buildingName2 = "Gilbert Hall",
           buildingAddress1 = "2701 SW Campus Way",
           buildingAddress2 = "2100 SW Monroe Ave";
    
    int studentAge = 25,
        instructorAge = 66,
        buildingSize1 = 235906,
        buildingSize2 = 85709;
    
    double GPA = 4.0,
           rating = 3.5;

    Menu infoMenu;

    //Dynamically creating Student and Instructor objects
    Person *student = new Student(studentName, studentAge, GPA);
    Person *instructor = new Instructor(instructorName, instructorAge, rating);

    //Dynamically creating vector, adding student and instructor to vector
    vector <Person *> people;
    people.push_back(student);
    people.push_back(instructor);

    //Dynamically creating Building objects
    Building *building1 = new Building(buildingName1, buildingAddress1, 
                                       buildingSize1);
    Building *building2 = new Building(buildingName2, buildingAddress2, 
                                       buildingSize2);

    //Creating vector, adding buildings to vector
    vector <Building *> buildings;
    buildings.push_back(building1);
    buildings.push_back(building2);

    //Passing people and buildings vectors to University constructor
    University oregonState(people, buildings);

    cout << "Note: Extra credit is implemented." << endl;
    cout << "This program will record information about" << endl
         << "buildings and people at Oregon State University." << endl << endl;
    cout << "One student, one instructor, and" << endl
         << "two buildings are already recorded." << endl;

    //Printing menu for user, ask to input what action to perform
    choice = infoMenu.universityInfo();

    while (choice != 8)
    {
        //Printing name, address, and size of all buildings
        if (choice == 1)
        {
            oregonState.printBuildingInfo();
        }

        //Printing name, age and GPA of students or rating of instructors
        else if (choice == 2)
        {
            oregonState.printPeopleInfo();
        }

        //Getting a person to do work
        else if (choice == 3)
        {
            string nameForWork;

            //Listing names of people that can perform work
            nameForWork = infoMenu.doWorkMenu(oregonState.getPeopleVector());
            oregonState.workPerson(nameForWork);
        }

        //Add a person to directory
        else if (choice == 4)
        {
            oregonState.addPerson();
        }

        //Add a building to directory
        else if (choice == 5)
        {
            oregonState.addBuilding();
        }

        //Save information about people to file
        else if(choice == 6)
        {
            oregonState.writeFile();
        }

        //Read information about people from file
        else if(choice == 7)
        {
            oregonState.readFile();
        }

        //Asking user to select another option to perform
        choice = infoMenu.universityInfo();
    }

    cout << "Goodbye!" << endl;

    return 0;
}