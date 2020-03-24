/*********************************************************************
** Program name: lab4
** Author:       Rebekah Koon
** Date:         7/18/19
** Description:  Header file for the Building class, which keeps track
**               of a building's name, address, and size in square
**               feet. Has constructors for setting these values, 
**               functions for setting the name, address, and size of
**               a building, and functions for getting the name, 
**               address, and size of a building.
*********************************************************************/

#ifndef BUILDING_HPP
#define BUILDING_HPP

#include <string>

using std::string;

class Building
{
    private:
        string name;
        string address;
        int size;
    
    public:
        Building();
        Building(string, string, int);

        void setName(string);
        void setAddress(string);
        void setSize(int);
        
        string getName();
        string getAddress();
        int getSize();

        ~Building();
};

#endif