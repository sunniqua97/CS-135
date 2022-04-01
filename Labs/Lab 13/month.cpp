/*
Author: Sunniyatul Quaderin
Course: CSCI-136
Instructor: Gwenael Gatto
Assignment: Lab1D

This program takes user inputted year and months 
and returns the number of days within the month.
During leap years the number of days in February is affected. 

*/

#include <iostream>

using namespace std;

int main()
{

    int useryear, usermonth;                // stores user inputted year and month
    cout << "Enter year: ";
    cin >> useryear;
    
    cout << "Enter month: ";
    cin >> usermonth;
    
    int days;                               // stores the final amount of days in month
    
    
    
        
    bool isLeapYear;                        // check to see if the year is a leap year
    if (useryear % 4 != 0){                 // if the year isn't divisble by 4, its common            
        
        isLeapYear = false;
    }
    else if ( useryear % 100 != 0){         // if it's divisible by 4 and not by 100, its  a leap year
        
        isLeapYear = true;
        
    }
    else if (useryear % 400 != 0){          // if it's divisble by 4 and 100, and not 400, its a common year
        
        isLeapYear = false;
        
        
    }
    else{
        isLeapYear = true;                // anything else is a leap year
    }   
    
                                        // now determines the number of days in the month
    
    if (usermonth == 2){                // if february is during a leapyear it has 29 days, otherwise 28
        if (isLeapYear){
            days = 29;
        }
        else{
            days = 28;
        }
    }
    else if (((usermonth < 8) and (usermonth % 2 == 1)) or ((usermonth > 7) and (usermonth % 2 == 0))) {
        days = 31;                      // months that are number 1, 3, 5, 7, 8, 10, 12 have 3o days
    }
    
    else {
        days = 30;                      //otherwise 31 days 
    }
    
    cout << days << " days";            // outputs the number of days stored as the day value
}
