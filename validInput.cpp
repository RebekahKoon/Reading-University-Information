/*********************************************************************
** Program name: lab4
** Author:       Rebekah Koon
** Date:         7/18/19
** Description:  Source file for validInput functions. One function
**               determines if an integer inputted by the user is 
**               valid, another determines if an input is a valid
**               double value, and the final function determines if
**               a string input is valid.
*********************************************************************/

#include "validInput.hpp"

/***********************************************************************
** Description: Function validInput takes as parameters two integers
**              representing the range an integer should be in. Checks 
**              to see if the string is an integer. If it is not a 
**              positive integer or within the specified range, asks 
**              user to reenter answer. If the integer is within range,
**              returns the string as an integer.
**              Source: adapted from my project 1 assignment.
***********************************************************************/
int validInput(int minNumber, int maxNumber)
{
    bool valid;
    int numberInt;
    string answer;

    do
    {
        getline(cin, answer);
        valid = true;

        //If string is empty
        if (answer.empty())
        {
            valid = false;
        }

        //Checking to see if the string is a positive integer
        for (int i = 0; i < answer.length(); i++)
        {
            if (!isdigit(answer[i]))
            {
                valid = false;
            } 
        }

        if (valid)
        {
            //Converting to an integer to check if it is within the min/max range
            numberInt = atoi(answer.c_str());

            //Checking to see if the integer is between the min/max range
            if (numberInt < minNumber || numberInt > maxNumber)
            {
                valid = false;
            }
        }

        //Reenter input if not a valid response
        if (!valid)
        {
            cout << "Please only type integers from "
                 << minNumber << " to " << maxNumber << ": ";
        }
    } while (valid == false);

    return numberInt;
}


/***********************************************************************
** Description: validInput takes two double parameters representing the
**              minimum and maximum amount a number can be. Checks to
**              see if a string input is a valid double and within the 
**              correct range. Asks to reenter answer if not a double
**              Returns the string as a double after validating input.
**              Source: https://stackoverflow.com/questions/447206/
**              c-isfloat-function
***********************************************************************/
double validInput(double minNumber, double maxNumber)
{
    double ansDouble;
    string answer;
    bool valid;
    do
    {
        getline(cin, answer);
        valid = false;

        //Determining if input can be a double value
        istringstream iss(answer);
        iss >> noskipws >> ansDouble;

        //If input can be a double
        if (iss.eof() && !iss.fail())
        {
            valid = true;
        }

        //Checking to see if value is within correct range
        if (ansDouble < minNumber || ansDouble > maxNumber)
        {
            valid = false;
        }

        //Reentering number if not valid
        if (!valid)
        {
            cout << fixed << showpoint << setprecision(2);
            cout << "Please only enter a number from "
                 << minNumber << " to " << maxNumber << ": ";
        }
    } while (valid == false);
    
    return ansDouble;
}


/***********************************************************************
** Description: validInput gets user input concerning the name of a
**              person. Asks user to reenter input if not valid. Returns
**              the user's answer after validating input.
**              Source: Adapted from project 1 validInput function
***********************************************************************/
string validInput()
{
    bool valid;
    string answer;

    do
    {
        getline(cin, answer);
        valid = true;

        //If string is empty
        if (answer.empty())
        {
            valid = false;
        }

        //If answer contains only whitespace
        if (answer.find_first_not_of(' ') == string::npos)
        {
            valid = false;
        }

        //Reentering name if not valid
        if (!valid)
        {
            cout << "Incorrect input. Please enter again: ";
        }
    } while (valid == false);
    
    return answer;
}