/*********************************************************************
** Program name: lab4
** Author:       Rebekah Koon
** Date:         7/18/19
** Description:  Implementation file for the Student class, which is 
**               derived and inherits from the Person class. Has 
**               functions to set and get the GPA of a student, a 
**               function that prints how much work a student does, 
**               and a function to return the status of a student.
*********************************************************************/


#include "Student.hpp"


/*********************************************************************
** Description: Default constructor for the Student class, which sets
**              the GPA of a student. The Person class default
**              constructor sets the name and age of the student.
*********************************************************************/
Student::Student(): Person()
{
    GPA = 0.0;
}


/*********************************************************************
** Description: Constructor for the Student class, which takes in the 
**              name, age, and GPA of a student in as parameters. Sets
**              the GPA of a student and uses the Person class 
**              constructor to set the name and age of the student.
*********************************************************************/
Student::Student(string nameIn, int ageIn, double GPAIn):
         Person(nameIn, ageIn)
{
    setGPA(GPAIn);
}


/*********************************************************************
** Description: Void member function setGPA takes in the GPA of a 
**              student as a parameter. Uses this value to set the
**              GPA variable.
*********************************************************************/
void Student::setGPA(double GPAIn)
{
    GPA = GPAIn;
}


/*********************************************************************
** Description: Member function getGPA returns the GPA of a student.
*********************************************************************/
double Student::getGPA()
{
    return GPA;
}


/*********************************************************************
** Description: Void member function do_work randomly generates a 
**              random number representing the hours of homework a
**              student did in one day. Prints how many hours the
**              student worked.
*********************************************************************/
void Student::do_work()
{
    int hoursWorked;
    const int MAX_HOURS = 16;

    //Setting seed for random number
    unsigned seed;
    seed = time(0);
    srand(seed);

    //Finding random amount of hours worked
    hoursWorked = rand() % MAX_HOURS + 1;

    cout << name << " did " << hoursWorked << " hours of homework." << endl;
}


/*********************************************************************
** Description: Member function findPersonStatus returns the enum
**              value associated with being a student.
*********************************************************************/
PersonStatus Student::findPersonStatus()
{
    return STUDENT;
}


/*********************************************************************
** Description: Destructor for the Student class.
*********************************************************************/
Student::~Student()
{
}