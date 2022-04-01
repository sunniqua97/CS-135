/*
Author: Sunniyatul Quaderin
Course: CSCI-136
Instructor: Gwenael Gatto
Assignment: Lab2C

This program creates an array of ten integers 
and allows the user to edit the indices with any values 
as long as the inputted index (i) is valid. 

*/

#include <iostream>

using namespace std;

int main()
{
    
    int i, v;
    int myData[10];
    for (int i = 0; i < 10; i++){               // sets all values of myData to 1
        myData[i] = 1;
    }
    do{
        for (int c = 0; c < 10; c++){           // prints all the values in the array myData
            cout << myData[c] << " ";
        }
        cout << endl;
        cin >> i;                               // user inputted index of myData
        cin >> v;                               // value to be assigned to index i of myData
        if ((i < 10) and (i >= 0)){
            myData[i] = v;
        }
        else{
            cout << "Index out of range. Exit.";
        }
        
    } while((i < 10) and (i >= 0));             // if the inputted index is within range the loop will continue


}
