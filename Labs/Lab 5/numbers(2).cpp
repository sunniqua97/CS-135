/*
Author: Sunniyatul Quaderin
Course: CSCI-136
Instructor: Gwanael Gatto
Assignment: Lab 5[C] Numbers


This program will ask the user to inputuean integer value. 
Afterwards it will determine the next highest prime number greater than 
the given integer value

ex:

Enter an integer: 5

7

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


} // end of isDivisibleBy (int n, int d)


bool isPrime(int n){
// determines whether a given int n is a prime integer
// If so, returns true, if not returns false. 

	bool prime = true;
	/* bool prime is true if the number is prime and false otherwise. 
	   function will assume number is prime unless it finds a divisible integer */
	

	for (int counter = 2; counter < n ; counter++){ // parses through every value from 2 to n 
		
		
		
		if (isDivisibleBy( n, counter)){ // check if any of the counter values is divides n cleanly. 
						
		
			prime = false; // if n is divisible cleanly, it is not prime, thus boolean prime is false. 

		}

	
	}

	if (n == 2) {
	// 2 is prime number, so boolean prime is set to true.

	prime = true;
	
	}
	
	if (n <= 1){
	// any number less than or equal to 1 is prime, so the function will set boolean prime to false. 

	prime = false;
	
	}

	return prime;


} // end of isPrime(int n)


int nextPrime(int num){
// finds the next highest prime number greater than int n

	bool primefound = false; // primefound is true if a prime number higher is found and false otherwise
				 

	int higherprime = num; // stores the int num value as higherprime in order

	while (not primefound){ // repeats as long as prime found is false, and if a prime number is found,
   				// primefound is set to true which stops the while loop
		
		higherprime++; // incrementally increasing higherprime by 1 until the next prime is found. 

		if (isPrime(higherprime)){
		
			primefound = true; // stops the while loop

		}
		

	}

	return higherprime; // returns the last stored value of higher prime which will be the next highest prime. 

} // end of nextPrime(int num)

int main(){
	
	int firstnum;
	// creates int value to store the user input 

	cout << "Enter an integer: ";
	cin >> firstnum;
	// stores the first user input as the int firstnum

	cout << nextPrime(firstnum) << endl;

	
} // end of main()
