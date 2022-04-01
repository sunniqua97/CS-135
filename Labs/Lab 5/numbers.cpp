/*
Author: Sunniyatul Quaderin
Course: CSCI-136
Instructor: Gwanael Gatto
Assignment: Lab 5[A] Numbers


This program will ask the user to input two integer values. 
Afterwards it will determine wheher the first integer value given
is divisible by the second. If it is divisible the program will output 
Yes. If not, it will output No. 

ex:

Enter an integer: 5
Enter an integer: 4

No

*/


#include <iostream>

using namespace std;

bool isDivisibleBy (int n, int d){
// function determines whether int n is cleanly divisible by int d. 
// if it is cleanly divisible, returns the boolean true. If not, 
// it returns false. 
	
	if (d == 0){

		/* in the case the second integer d is zero
		returns false since nothing can be divided by zero */
			
		
		return false;
	}

	if ((n % d) == 0){
		/* if the remainder of n and d is zero
		then the two integers are cleanly divisible 
		and thus the function will return true */

		return true;

		
	}

	else{
		/* if the remainder of n and d isn't zero
		then the two integers are not cleanly divisible 
		and thus the function will return false*/

		return false;
	}


}

int main(){
	
	int firstnum, secnum;
	// create two int values to store the user input integers 

	cout << "Enter an integer: ";
	cin >> firstnum;
	// stores the first user input as the int firstnum

	cout << "Enter an integer: ";
	cin >> secnum;
	// stores the second user input as the int secnum

	if (isDivisibleBy (firstnum , secnum)){
	
	cout << "Yes" << endl;
	
	// if the two numbers are divisible, returns Yes

	}
	else{

	// if not then returns No

	cout << "No" << endl;

	}
	


}
