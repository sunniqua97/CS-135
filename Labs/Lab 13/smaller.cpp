/*
Author: Sunniyatul Quaderin
Course: CSCI-136
Instructor: Gwenael Gatto
Assignment: Lab1A

This program takes two user integer inputs and returns
the smaller of the two integers

*/

#include <iostream>

using namespace std;

int main()
{

    int firstint, secint;           // stores user inputs
    int smallerint;
    
    cout << "Enter the first number:";
    cin >> firstint;
    cout << "Enter the second number:";
    cin >> secint;                  // stores the lesser int value
    
    if (secint > firstint){         // checks which value is the lesser and stores it as smallerint
        smallerint = firstint;
    }
    else if (firstint > secint){
        smallerint = secint;
    }
    
    cout << "The smaller of the two is " << smallerint;     //outputs the smaller int 

}
