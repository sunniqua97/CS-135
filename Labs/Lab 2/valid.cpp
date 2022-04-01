/*
Author: Sunniyatul Quaderin
Course: CSCI-136
Instructor: Gwenael Gatto
Assignment: Lab2A
This program checks to see if a user input is between 0 and 100.
If so, it'll return the square of its value.
If not, it'll ask the user to re-enter a value within the range. 
*/

#include <iostream>

using namespace std;

int main()
{
    int userinput;                                      // takes the userinputted integer
    cin >> userinput;
    
    while(not((userinput < 100) and (userinput > 0))){  // checks to see if userinput meets the defined range 
        cin >> userinput;                               // asks user to re-enter an integer if not
    }
    
    int output = userinput * userinput;                 // calculates the square of the userinput and stores it as the output
    
    cout << output;                                     // returns the output

    return 0;
}
