/*********************************************************************
** Program name: lab4
** Author:       Rebekah Koon
** Date:         7/18/19
** Description:  Implementation file for the Person class, which keeps
**               track of information about people at a university. 
**               Has functions to set and get the name and age of a 
**               person. Also has virtual functions to have a person
**               do work and to find the person's status (whether they
**               are a student or instructor).
*********************************************************************/

#include "Person.hpp"


/*********************************************************************
** Description: Default constructor for the Person class, which sets
**              the name and age of a person.
*********************************************************************/
Person::Person()
{
    name = "";
    age = 0;
}


/*********************************************************************
** Description: Constructor for the Person class. Takes the name and
**              age of a person as parameters. Uses these values to 
**              set the name and age variables.
*********************************************************************/
Person::Person(string nameIn, int ageIn)
{
    setName(nameIn);
    setAge(ageIn);
}


/*********************************************************************
** Description: Void member function setName takes the name of a 
**              person as a parameter. Uses this to set the name
**              variable.
*********************************************************************/
void Person::setName(string nameIn)
{
    name = nameIn;
}


/*********************************************************************
** Description: Void member function setAge takes the age of a person
**              as a parameter. Uses this to set the age variable.
*********************************************************************/
void Person::setAge(int ageIn)
{
    age = ageIn;
}


/*********************************************************************
** Description: Member function getName returns the name variable.
*********************************************************************/
string Person::getName()
{
    return name;
}


/*********************************************************************
** Description: Member function getAge returns the age variable.
*********************************************************************/
int Person::getAge()
{
    return age;
}


/*********************************************************************
** Description: Void member function do_work randomly generates a 
**              random number representing the hours of work a person
**              did in one day. Prints how many hours the person
**              worked.
*********************************************************************/
void Person::do_work()
{
    int hoursWorked;
    const int MAX_HOURS = 16;

    //Setting seed for random number
    unsigned seed;
    seed = time(0);
    srand(seed);

    //Finding random amount of hours worked
    hoursWorked = rand() % MAX_HOURS + 1;

    cout << name << " did " << hoursWorked << " hours of work." << endl;
}


/*********************************************************************
** Description: Destructor for the Person class.
*********************************************************************/
Person::~Person()
{
}