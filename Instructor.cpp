/*********************************************************************
** Program name: lab4
** Author:       Rebekah Koon
** Date:         7/18/19
** Description:  Implementation file for the Instructor class, which
**               is derived and inherits from the Person class. Has
**               functions to set and get an instructor's rating, a
**               function that prints how much work an instructor did,
**               and a function that returns the instructor's status.
*********************************************************************/

#include "Instructor.hpp"


/*********************************************************************
** Description: Default constructor for the Instructor class, which
**              sets the rating of an instructor. The Person class
**              default constructor sets their name and age.
*********************************************************************/
Instructor::Instructor(): Person()
{
    rating = 0.0;
}


/*********************************************************************
** Description: Constructor for the Instructor class, which takes in
**              the name, age, and rating of an instructor. Sets the
**              rating of an instructor and uses the Person class to
**              set the name and age of the instructor.
*********************************************************************/
Instructor::Instructor(string nameIn, int ageIn, double ratingIn)
           : Person(nameIn, ageIn)
{
    setRating(ratingIn);
}


/*********************************************************************
** Description: Void member function setRating takes in the rating of
**              an instructor as a parameter. Uses to set the rating
**              of the instructor.
*********************************************************************/
void Instructor::setRating(double ratingIn)
{
    rating = ratingIn;
}


/*********************************************************************
** Description: Member function getRating returns the rating of the
**              instructor.
*********************************************************************/
double Instructor::getRating()
{
    return rating;
}


/*********************************************************************
** Description: Void member function do_work randomly generates a 
**              number representing the hours an instructor graded
**              papers. Prints how many hours the instructor worked.
*********************************************************************/
void Instructor::do_work()
{
    int hoursWorked;
    const int MAX_HOURS = 16;

    //Setting seed for random number
    unsigned seed;
    seed = time(0);
    srand(seed);

    hoursWorked = rand() % MAX_HOURS + 1;

    cout << name << " graded papers for " << hoursWorked << " hours." << endl;
}


/*********************************************************************
** Description: Member function findPersonStatus returns an enum
**              value associated with being an instructor.
*********************************************************************/
PersonStatus Instructor::findPersonStatus()
{
    return INSTRUCTOR;
}


/*********************************************************************
** Description: Destructor for the Instructor class.
*********************************************************************/
Instructor::~Instructor()
{
}