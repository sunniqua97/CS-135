/*
Author: Sunniyatul Quaderin
Course: CSCI-136
Instructor: Gwenael Gatto
Assignment: Lab2D

This program uses an array to compute 
fibonaccis sequence up until 60 terms. 
What we notice when it computes is that numbers become 
negative as we expect them to approach the billions since 
the range limit of the int type prevents it from 
going further. 

*/

#include <iostream>

using namespace std;

int main(){
    
    
    int fib[60];
    fib [0] = 0;                        // sets the initial values of fibonacci 
    fib [1] = 1;
    
    
    for (int i = 2; i < 60 ;i++){       
        
        fib[i] = fib[i-1] + fib[i-2];   // every next value is determined by the last two
        
    }
    
    for (int i = 0; i < 60; i++){       // prints the whole array fib
        cout << fib[i] << endl;
    }
    

}
