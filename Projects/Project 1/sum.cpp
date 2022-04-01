/*
Author: Sunniyatul Quaderin
Course: CSCI-135
Instructor: Gennadiy Maryash
Assignment: Project1A[Sum]


This program will take a text file 
and read the numbers in the file and return
the sum of all the numbers. ex: ./sum < textexample.txt
would return the total of all the numbers in the text file

ex:
text file containing the numbers:

5 4 2 18 18

would return 

47


*/



#include <iostream>

using namespace std;

int main(){

	int num, total; 
	// num is a placeholder for every number in the text file
			
	total = 0;
	//total is a counter for the total of all the numbers (num) in the text file

	while(cin >> num ){
		// reads through every character in the text file and 
		// represents it as num. Stops parsing when there 
		// is no more char values to represent
		
		total += num; 
		// each num read is added to the total counter

	} // end of while cin >> num loop

	cout << total << endl;
	// total is outputed 


} // end of int main 
