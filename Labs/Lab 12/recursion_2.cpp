/*
Author: Sunniyatul Quaderin
Course: CSCI-136
Instructor: Gwanael Gatto 
Assignment: LAB 12 B


This program defines a function (printRange) which 
will all numbers in the user inputted range left to 
right, seperated by spaces. 

Lab B

This program defines a function sumRange which will return
the value of the sum of all numbers in the range from left
to right  (inclusive).

*/

#include <iostream>
using namespace std;

void printRange(int left, int right);
int sumRange(int left, int right);

int main(){
    
	cout << sumRange(4, 10);
}

int sumRange(int left, int right) {
// add up all numbers in the range from left to right

	if (left <= right) {
		// keep adding numbers in range until range limit reached
		return left + sumRange(left + 1, right);
		
	}

	else {
		// return zero since range is empty 
		return 0;
	}


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