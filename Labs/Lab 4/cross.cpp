/*
Author: Sunniyatul Quaderin
Course: CSCI-136
Instructor: Gwenael Gatto 
Assignment: LAB 4C


This program takes one user input (shape) and 
prints out a diagonal cross of the size of the 
given input shape. 



*/



#include <iostream>

using namespace std;

int main(){


	int width, height, shape;
	
	cout << "Input size: ";
	cin >> shape;
	
	width = shape;
	height = shape;
	
	
	cout << "\nShape:\n";
	
	
	for (int row = 0; row < height; row++){
		
		
		for (int col = 0; col < width; col++){
		
			if ((row == col) or (row + col == (shape - 1))){
			
				cout << "*";
				
			}
			else {
			
				cout << " ";
				
			}
				
				
		}
		

		
		cout << "\n";
		
	
	}
	

	
	
	return 0;
	
	
	
	



}



