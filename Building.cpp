/*********************************************************************
** Program name: lab4
** Author:       Rebekah Koon
** Date:         7/18/19
** Description:  Implementation file for the Building class, which 
**               keeps track of a building's name, address, and size 
**               in square feet. Has constructors for setting these
**               values, functions for setting the name, address, and 
**               size of a building, and functions for getting the
**               name, address, and size of a building.
*********************************************************************/

#include "Building.hpp"


/*********************************************************************
** Description: Default constructor for the Building class, which sets
**              the values for the name, address, and size of a 
**              building.
*********************************************************************/
Building::Building()
{
    name = "";
    address = "";
    size = 0;
}


/*********************************************************************
** Description: Constructor for the Building class that takes in the
**              name, address, and size of a building as parameters.
**              Uses these values to set the name, address, and size
**              variables for the building.
*********************************************************************/
Building::Building(string nameIn, string addressIn, int sizeIn)
{
    setName(nameIn);
    setAddress(addressIn);
    setSize(sizeIn);
}


/*********************************************************************
** Description: Void member function setName takes a string as a
**              parameter for the name of a building. Assigns value
**              to the name variable.
*********************************************************************/
void Building::setName(string nameIn)
{
    name = nameIn;
}


/*********************************************************************
** Description: Void member function setAddress takes a string as a
**              parameter for the address of a building. Assigns value
**              to the address variable.
*********************************************************************/
void Building::setAddress(string addressIn)
{
    address = addressIn;
}


/*********************************************************************
** Description: Void member function setSize takes an integer as a 
**              parameter for the size of a building. Assigns value
**              to the size variable.
*********************************************************************/
void Building::setSize(int sizeIn)
{
    size = sizeIn;
}


/*********************************************************************
** Description: Member function getName returns a building's name.
*********************************************************************/
string Building::getName()
{
    return name;
}


/*********************************************************************
** Description: Member function getAddress returns the address of
**              a building.
*********************************************************************/
string Building::getAddress()
{
    return address;
}


/*********************************************************************
** Description: Member function getSize returns a building's size
**              in square feet.
*********************************************************************/
int Building::getSize()
{
    return size;
}


/*********************************************************************
** Description: Destructor for the Building class.
*********************************************************************/
Building::~Building()
{
}