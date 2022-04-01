/*
Author: Sunniyatul Quaderin
Course: CSCI-136
Instructor: Gwanael Gatto 
Assignment: LAB 12 A


This program defines a function (printRange) which 
will all numbers in the user inputted range left to 
right, seperated by spaces. 

*/

#include <iostream>
using namespace std;

void printRange(int left, int right);

int main(){
    
    
}

void printRange(int left, int right){
// prints numbers from left to right seperated by spaces
    if (left <= right){ 
    // keep printing numbers in range until range limit reached
            cout << left ;
            printRange(left + 1, right);
    }
    
    if (left > right){
            // do nothing since there's no numbers in range
    }
    
}