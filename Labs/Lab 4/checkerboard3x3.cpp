/*
Author: Sunniyatul Quaderin
Course: CSCI-136
Instructor: Gwenael Gatto 
Assignment: LAB 4G

This program takes the users input of width
and height then displays a checkerboard with 
3 by 3 star squares. The width of the checkerboard
and the height is measured by the number of stars. 

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
		
			if (row % 6 < 3){
			
				if (col % 6 < 3){
				
					cout << "*";
				
				}
				
				else{
				
				cout << " ";
				
				}
				 
			
			}
			
			else{
			
				if (col % 6 < 3){
					
					cout << " ";
					
				}
				else {
				
					cout << "*";
				
				}
			
				
				
			}
		
		}
		cout << "\n";
		
	
	}
	
	
	
	return 0;
	
	
	
	



}



