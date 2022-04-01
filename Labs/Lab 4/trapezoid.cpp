/*
Author: Sunniyatul Quaderin
Course: CSCI-136
Instructor: Gwenael Gatto 
Assignment: LAB 4F


This program takes a width and height input 
and prints an upside-down trapezoid of the 
given dimensions. However, if the dimensions 
given by the user are not appropriate to make 
an upside down trapezoid, the prompt will display 
"Impossible shape!"

*/






#include <iostream>
#include <math.h>


using namespace std;

int main(){

	int width, height;

	cout << "Input width: ";
	cin >> width;
	// Asks user to input the width
	
	cout << "Input height: ";
	cin >> height;
	// Asks user to input the height
	
	
	int space = 0;
	int stars = width;
	int test = ceil(0.5 * width);
	
	
	
	if (height > (test)) { 
	
		cout << "\nImpossible shape!";
	
	}
	
	else{
	
		cout << "\nShape:\n";
	
		for (int row = 0; row < height; row	++){
			
			for (int counter = space; counter > 0; counter --){
			
			cout << " ";
			
			
			}
			// for counter end 
			
			for (int counter2 = stars; counter2 > 0; counter2 --){
			
			cout << "*";
					
			
			}// for counter2 end 
			
			
			
			stars -= 2;
			space += 1;
			cout << "\n"; 
			// Go on to the next line 
			
		
		}// for row end
		
	}//else end 



	
	
	
	

}//main


