/*
Author: Sunniyatul Quaderin
Course: CSCI-136
Instructor: Gwenael Gatto 
Assignment: LAB 4B


This program takes two user inputs, the width and height,
then appropriately displays the asterisks corresponding to 
the user's inputs alternation between spaces and asterisks



*/



#include <iostream>

using namespace std;

int main(){


	int width, height;
	
	cout << "Input width: ";
	cin >> width;
	
	cout << "Input height: ";
	cin >> height;
	
	cout << "\nShape:\n";
	
	
	for (int row = 0; row < height; row++){
		
		
		for (int col = 0; col < width; col++){
		
			if (row % 2 == 0){
			
				if (col % 2 == 0){
				// print a star
				
				cout << "*";
				
				}
				
				else{
				// print an asterick
				
				cout << " ";
				
				}
			
			
			
			}
			
			else{
			
			
				if (col % 2 == 0){
				// print an asterick
				
				cout << " ";
				
				}
				
				else{
				// print a star
				
				cout << "*";
				
				}
				
				
			}
		
		}
		cout << "\n";
		
	
	}
	
	
	
	return 0;
	
	
	
	



}



