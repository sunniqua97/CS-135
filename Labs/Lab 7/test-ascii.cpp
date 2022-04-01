/*
Author: Sunniyatul Quaderin
Course: CSCI-136
Instructor: Gwanael Gatto
Assignment: Lab 7[A] Test-Ascii


This program take a user inputted string and 
returns each character from the input as ASCII codes. 
Each character is displayed with the ASCII equivalent 
next to it seperated by a space. 


 */


#include <iostream>

using namespace std;

int main(){


	string x;					//stores the user inputted line
	cout << "Input: ";
	getline(cin, x);				//recieves user input with spaces 
	cout << endl;
	
	
	for (int i = 0; i < x.length(); i++){		//parses through every character in string 
		
		cout << x[i] << " " << (int)x[i] << endl;
	

	}




}// end of main
