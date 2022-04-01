/*
Author: Sunniyatul Quaderin
Course: CSCI-136
Instructor: Gwanael Gatto 
Assignment: LAB 12 D

LAB A 

This program defines a function (printRange) which 
will all numbers in the user inputted range left to 
right, seperated by spaces. 

Lab B

This program defines a function sumRange which will return
the value of the sum of all numbers in the range from left
to right  (inclusive).

LAB C

This program has a function sumArray, which will take an array and 
int input and will return the sum of the elements of the array

LAB D

This program contains a function, isAlphanumeric, which will return true
if all characters in a user inputted string are letters and digits. If not,
returns false.

*/

#include <iostream>
using namespace std;

void printRange(int left, int right);
int sumRange(int left, int right);
int sumArray(int *arr, int size);
bool isAlphanumeric(string s);

int main(){
    
	cout << sumRange(4, 10);
}

bool isAlphanumeric(string s) {
// checks to see if a string contains only alphanumeric chars

	if (s.empty()) {
		// check whether string is empty after recursions 

		return true;
	}
	else if (isalpha(s[0]) or isdigit(s[0])) {
		// check the other terms 
		int x = s.length() - 1;
		return isAlphanumeric(s.substr(1, x));
	}
	else {
		return false;
	}
	


}

int sumArray(int *arr, int size) {
// sums up all int terms of any array 

	if (size == 0) {
		return 0;
	}
		
	else {
		// sum up each term starting from the last term 
		return arr[size - 1] + sumArray(arr, size - 1);
	}
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