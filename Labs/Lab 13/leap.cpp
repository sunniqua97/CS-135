/*
Author: Sunniyatul Quaderin
Course: CSCI-136
Instructor: Gwenael Gatto
Assignment: Lab1C

This program takes user inputted year and returns 
"Leap Year" if the input is a leap year, and "Common Year", 
if not a leap year.

*/

#include <iostream>

using namespace std;

int main()
{

    int useryear;
    cin >> useryear;
    
    if (useryear % 4 != 0){                 // if the year isn't divisble by 4, its common            
        
        cout << "Common Year";
    }
    else if ( useryear % 100 != 0){         // if it's divisible by 4 and not by 100, its  a leap year
        
        cout << "Leap Year";
        
    }
    else if (useryear % 400 != 0){          // if it's divisble by 4 and 100, and not 400, its a common year
        
        cout << "Common Year";
        
        
    }
    else{
        cout << "Leap Year";                // anything else is a leap year
    }   
}
