/*
Author: Sunniyatul Quaderin
Course: CSCI-136
Instructor: Gwenael Gatto 
Assignment: LAB 4A


This program takes two user inputs, the width and height,
then appropriately displays the asterisks corresponding to 
the user's inputs



*/
#include <iostream>

using namespace std;

int main(){
	
	
	
	int width, height;
	
	cout << "Input width: ";
	cin >> width;
	
	cout << "Input height: ";
	cin >> height;
	
	cout <<"\nShape:\n";
	
	for (int counter = height; counter > 0; counter --){
	
		for (int counter2 = width; counter2 > 0; counter2 --){
		
			cout << "*";
		}
		cout << "\n";
		
		
	}
	
	
	return 0;
	
	
	
	
	

}


