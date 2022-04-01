/*
Author: Sunniyatul Quaderin
Course: CSCI-136
Instructor: Gwenael Gatto
Assignment: Lab1B

This program takes three user integer inputs and returns
the smaller of the three integers

*/

#include <iostream>

using namespace std;

int main()
{

    int firstint, secint, thirdint;         // stores user inputs
    int smallerint;                         // stores the lesser int value
    
    cout << "Enter the first number:";
    cin >> firstint;
    cout << "Enter the second number:";
    cin >> secint;     
    cout << "Enter the third number";
    cin >> thirdint;
    
    
    
    if (secint > firstint){                 // checks which value is the smallest and stores it as smallerint
        smallerint = firstint;
    }
    else if (firstint > secint){
        smallerint = secint;
    }
    
    if (smallerint > thirdint){             // compares the smallest of the first two ints with the third int
        smallerint = thirdint;
    }
    
    cout << "The smaller of the three is " << smallerint;     //outputs the smaller int 

}
