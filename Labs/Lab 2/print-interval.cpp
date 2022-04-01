/*
Author: Sunniyatul Quaderin
Course: CSCI-136
Instructor: Gwenael Gatto
Assignment: Lab2B

Asks the user to input an upper and lower limits and prints numbers
from the lower limit up to, but not including, the upper limit. 

*/

#include <iostream>

using namespace std;

int main()
{
    int lower, upper;                                       // stores the lower limit, upper limit values
    cin >> lower;   
    cin >> upper;
    
    for (int counter = lower; counter < upper; counter++){  // loops until the number before the upper limit
        cout << counter << " ";                                    // prints each number
    }
  
  
  
    return 0;
}
