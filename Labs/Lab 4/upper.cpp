/*
Author: Sunniyatul Quaderin
Course: CSCI-136
Instructor: Gwenael Gatto 
Assignment: LAB 4E


This program takes a length input and prints out
the upper right half of a square with such side length.

*/






#include <iostream>

using namespace std;

int main(){

	int length;
	cout << "Input side length: ";
	cin >> length;
	// Asks user to input the length 
	
	cout << "\nShape:\n";
	
	for (int row = 0; row < length; row++){
	
		for (int col = 0; col < length; col++){
		
			if (col >= row){
			
			cout << "*";
			
				
			}
			
			else{
			
			cout << " ";
			
			}
		
		
		}// for col end
	
		
		cout << "\n"; 
		// Go on to the next line 
		
	
	}// for row end



	
	
	
	

}//main


