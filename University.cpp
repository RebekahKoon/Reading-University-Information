/*********************************************************************
** Program name: lab4
** Author:       Rebekah Koon
** Date:         7/18/19
** Description:  Implementation file for the University class, which
**               has a vector for people and a vector for buildings at
**               a university. Has functions for setting the name of a
**               university, setting the two vectors, taking in info
**               about people or buildings and then adding them as 
**               objects to the people or buildings vector, printing
**               info about the people or buildings, making a person
**               perform work, and reading or writing info to a file.
*********************************************************************/

#include "University.hpp"


/*********************************************************************
** Description: Default constructor for the University class that
**              sets the university's name to Oregon State University.
*********************************************************************/
University::University()
{
    universityName = "Oregon State University";
}


/*********************************************************************
** Description: Constructor for the University class that takes in
**              a vector of pointers to Person objects and a vector of
**              pointers to Building objects as parameters. Uses these
**              vectors to set people and buildings vectors.
*********************************************************************/
University::University(vector <Person *> peopleIn, 
                       vector <Building *> buildingsIn)
{
    universityName = "Oregon State University";

    setPeopleVector(peopleIn);
    setBuildingsVector(buildingsIn);
}


/*********************************************************************
** Description: Void member function setUniversityName takes the name
**              of a university as a parameter. Uses to set the 
**              universityName variable.
*********************************************************************/
void University::setUniversityName(string nameIn)
{
    universityName = nameIn;
}


/*********************************************************************
** Description: Void member function setPeopleVector takes a vector
**              of pointers to Person objects as a parameter. Uses to
**              set the people vector.
*********************************************************************/
void University::setPeopleVector(vector <Person *> peopleIn)
{
    people = peopleIn;
}


/*********************************************************************
** Description: Void member function setBuildingsVector takes a vector
**              of pointers to Building objects as a parameter. Uses
**              to set the buildings vector.
*********************************************************************/
void University::setBuildingsVector(vector <Building *> buildingsIn)
{
    buildings = buildingsIn;
}


/*********************************************************************
** Description: Void member function setPerson takes a pointer to a
**              Person object as a parameter. Adds the object to the
**              people vector.
*********************************************************************/
void University::setPerson(Person *personIn)
{
    people.push_back(personIn);
}


/*********************************************************************
** Description: Void member function setBuilding takes a pointer to a
**              Building object as a parameter. Adds the object to the
**              buildings vector
*********************************************************************/
void University::setBuilding(Building *buildingIn)
{
    buildings.push_back(buildingIn);
}


/*********************************************************************
** Description: Member function getUniversityName returns the name
**              of the university.
*********************************************************************/
string University::getUniversityName()
{
    return universityName;
}


/*********************************************************************
** Description: Member function getBuildingsVector returns the vector 
**              containing Building pointers with information about
**              the university's buildings.
*********************************************************************/
vector <Building *> University::getBuildingsVector()
{
    return buildings;
}


/*********************************************************************
** Description: Member function getPeopleVector returns the vector 
**              containing People pointers with information about
**              students and instructors at the university.
*********************************************************************/
vector <Person *> University::getPeopleVector()
{
    return people;
}


/*********************************************************************
** Description: Void member function addPerson asks user to input a
**              person's name, age, and GPA if a student or rating if
**              an instructor. Uses the information to make either a
**              Student or Instructor object and puts the object in
**              the people vector.
**              Source: https://www.learncpp.com/cpp-tutorial/
**              12-9-dynamic-casting/
*********************************************************************/
void University::addPerson()
{
    string name;

    int age,
        personType;

    double GPA,
           rating;

    const int STUDENT_AGE_MIN = 18,
              STUDENT_AGE_MAX = 100,
              INSTRUCTOR_AGE_MIN = 22,
              INSTRUCTOR_AGE_MAX = 100;

    const double GPA_MIN = 0.0,
                 GPA_MAX = 4.0,
                 RATING_MIN = 0.0,
                 RATING_MAX = 5.0;
    
    Person *person;

    cout << "Enter the person's name: ";
    name = validInput();

    cout << "Is the person a student or instructor? " << endl;
    cout << "Enter 1 for student or 2 for instructor: ";
    personType = validInput(STUDENT, INSTRUCTOR);

    //Sets name, age, and GPA if person is a student
    if (personType == STUDENT)
    {
        person = new Student;
        person->setName(name);

        cout << "Enter the student's age (number from 18 to 100): ";
        age = validInput(STUDENT_AGE_MIN, STUDENT_AGE_MAX);
        person->setAge(age);

        cout << "Enter the student's GPA (number from 0.0 to 4.0): ";
        GPA = validInput(GPA_MIN, GPA_MAX);
        dynamic_cast<Student *> (person)->setGPA(GPA);

        //Adding student to the people vector
        setPerson(person);
    }

    //Sets name, age, and rating if person is an instructor
    else if (personType == INSTRUCTOR)
    {
        person = new Instructor;
        person->setName(name);

        cout << "Enter the instructor's age (number from 22 to 100): ";
        age = validInput(STUDENT_AGE_MIN, STUDENT_AGE_MAX);
        person->setAge(age);

        cout << "Enter the instructor's rating (number from 0.0 to 5.0): ";
        rating = validInput(RATING_MIN, RATING_MAX);
        dynamic_cast<Instructor *> (person)->setRating(rating);

        //Adding instructor to the people vector
        setPerson(person);
    }

    cout << "Information about the person has been added." << endl;
}


/*********************************************************************
** Description: Void member function addBuilding asks the user to
**              type in information abouut a building. Uses the 
**              information to create a Building object and puts the
**              object within the buildings vector.
*********************************************************************/
void University::addBuilding()
{
    string name,
           address;

    int sizeSqFt;

    const int SQUARE_FEET_MIN = 1000,
              SQUARE_FEET_MAX = 300000;
    
    Building *campusBuilding = new Building;

    //Setting the building's name
    cout << "Enter a building's name: ";
    name = validInput();
    campusBuilding->setName(name);

    //Setting the building's address
    cout << "Enter the building's address: ";
    address = validInput();
    campusBuilding->setAddress(address);

    //Setting the building's size
    cout << "Enter the building's size in square feet"
         << " (number from 1000 to 300000): ";
    sizeSqFt = validInput(SQUARE_FEET_MIN, SQUARE_FEET_MAX);
    campusBuilding->setSize(sizeSqFt);

    //Adding the building to the vector
    setBuilding(campusBuilding);

    cout << "Information about the building has been added." << endl;
}


/*********************************************************************
** Description: Void function printBuildingInfo prints the name,
**              address, and size of each building at the university.
*********************************************************************/
void University::printBuildingInfo()
{
    cout << "Building information:" << endl;

    //Printing name, address, and size of each building
    for (int i = 0; i < buildings.size(); i++)
    {
        cout << buildings[i]->getName() << endl;
        cout << buildings[i]->getAddress() << endl;
        cout << buildings[i]->getSize() << " square feet" << endl << endl;
    }
}


/*********************************************************************
** Description: Void member function printPeopleInfo prints the name
**              and age of each person at the university. If the 
**              student is a peron, prints their GPA. If the person is
**              an instructor, prints their rating.
**              Source: http://www.cplusplus.com/forum/general/2710/
*********************************************************************/
void University::printPeopleInfo()
{
    cout << "Information about people at " << universityName << ":" << endl;

    //Print information about each person
    for (int i = 0; i < people.size(); i++)
    {
        cout << people[i]->getName() << endl;
        cout << "Age: " << people[i]->getAge() << endl;

        cout << fixed << showpoint << setprecision(2);
        //Printing GPA of students
        if ((people[i])->findPersonStatus() == STUDENT)
        {
            cout << "Student GPA: ";
            cout << (dynamic_cast<Student *> (people[i]))->getGPA() 
                 << endl << endl;
        }

        //Printing rating of instructors
        else if ((people[i]->findPersonStatus() == INSTRUCTOR))
        {
            cout << "Instructor rating: ";
            cout << (dynamic_cast<Instructor *> (people[i]))->getRating()
                 << endl << endl;
        }
    }
}


/*********************************************************************
** Description: Void member function workPerson takes a string for
**              a person's name as a parameter. If the person's name
**              is in the directory, calls function do_work in the
**              Person class to have the person do work. If not in
**              the directory, asks to input another name.
*********************************************************************/
void University::workPerson(string nameIn)
{
    bool inDirectory = false;

    //Making name lowercase to see if a match is in the directory
    transform(nameIn.begin(), nameIn.end(), nameIn.begin(), ::tolower);

    do
    {
        //Searching people vector to see if person is in directory
        for (int i = 0; i < people.size(); i++)
        {
            //Finding name of person, transforming to lowercase letters
            string name = people[i]->getName();
            transform(name.begin(), name.end(), name.begin(), ::tolower);

            //Calling Person function do_work to have person do work if a match
            if (nameIn == name)
            {
                inDirectory = true;
                people[i]->do_work();
            }
        }

        //If name not found
        if (inDirectory == false)
        {
            cout << nameIn << " was not in the directory. "
                 << "Enter a different name: ";
            nameIn = validInput();
        }
    } while (inDirectory == false);
}


/*********************************************************************
** Description: Void member function writeFile writes information
**              about people at the university to a file if the file
**              can be opened. Uses the people vector to get the
**              information to be written to the file.
**              Source: Lab 2 assignment, http://www.cplusplus.com/
**              forum/beginner/111860/
*********************************************************************/
void University::writeFile()
{
    string peopleFile = "peopleFile.txt";
    ofstream outPeople;

    cout << "People information will be saved to " << peopleFile << endl;

    //Open file to save people information to
    outPeople.open(peopleFile.c_str());

    //If the file does not open
    if (!outPeople)
    {
        cout << endl << "The file could not be opened." << endl;
    }

    //Writing information in vector to file
    for (int i = 0; i < people.size(); i++)
    {
        //Marking person as a student if person in vector is a student
        if ((people[i])->findPersonStatus() == STUDENT)
        {
            //Putting person's information within file
            outPeople << "Student " << people[i]->getName() << " " 
                      << people[i]->getAge() << " " 
                      << (dynamic_cast<Student *> (people[i]))->getGPA()
                      << endl;
        }

        //Marking person as an instructor if person in vector is an instructor
        else if ((people[i]->findPersonStatus() == INSTRUCTOR))
        {
            //Putting person's information within file
            outPeople << "Instructor " << people[i]->getName() << " "
                      << people[i]->getAge() << " "
                      << (dynamic_cast<Instructor *> (people[i]))->getRating()
                      << endl;
        }
    }

    cout << "Information has been saved to the file." << endl;
    outPeople.close();
}


/*********************************************************************
** Description: Void member function readFile opens a file to be read
**              if the file is available. Deletes current vector's
**              contents. Reads the information about each person in
**              the file. Creates a Person object with the information
**              and then adds the object to the people vector.
**              Source: https://stackoverflow.com/questions/3946558/
**              c-read-from-text-file-and-separate-into-variable
*********************************************************************/
void University::readFile()
{
    ifstream inPeople;

    string personStatus,
           name,
           line;
    
    int age;

    //standing variable is used for either GPA or instructor rating
    double standing;

    Person *personIn;

    //Open file to read
    inPeople.open("peopleFile.txt");

    //If file containing people can't be opened
    if (!inPeople)
    {
        cout << endl << "The file could not be opened." << endl;
    }

    else
    {
        //Deleting dynamically allocated memory in current vector
        for (int i = 0; i < people.size(); i++)
        {
            delete people[i];
        }

        //Clearing the current vector
        people.clear();
    
        //Reading people from file
        while(inPeople >> personStatus >> name >> age >> standing)
        {
            //If person in file defined as a student, add to vector as student
            if (personStatus == "Student")
            {
                personIn = new Student;

                //Setting information about student
                personIn->setName(name);
                personIn->setAge(age);
                (dynamic_cast<Student *> (personIn))->setGPA(standing);

                //Putting in the vector
                people.push_back(personIn);
            }

            //If defined as an instructor, add to vector as instructor
            else if (personStatus == "Instructor")
            {
                personIn = new Instructor;

                //Setting information about instructor
                personIn->setName(name);
                personIn->setAge(age);
                (dynamic_cast<Instructor *> (personIn))->setRating(standing);

                //Putting in the vector
                people.push_back(personIn);
            }
        }

        cout << "Information about people has been loaded from " 
             << "peopleFile.txt" << endl;
        inPeople.close();
    }
}


/*********************************************************************
** Description: Destructor for the University class that deletes
**              dynamically allocated memory in vectors.
*********************************************************************/
University::~University()
{
    for (int i = 0; i < people.size(); i++)
    {
        delete people[i];
    }

    for (int i = 0; i < buildings.size(); i++)
    {
        delete buildings[i];
    }
}