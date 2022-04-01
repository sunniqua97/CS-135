/*
Author: Sunniyatul Quaderin
Course: CSCI-136
Instructor: Gwanael Gatto
Assignment: Lab 5[G] Numbers


This program will ask the user to input two integer values. It will evaulate the range between
the two int values inclusively to find the greatest twin prime. if there are no twin primes it will 
return the value -1. 


Enter an integer: 6
Enter an integer: 9

7

*/


#include <iostream>
#include <math.h>


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
	
	
	if (n <= 1){
	// any number less than or equal to 1 is not prime, so the function will set boolean prime to false. 

	prime = false;
	
	}

	

	else {

	for (int counter = sqrt(n) + 1; counter > 1 ; counter--){ // parses through every value from 2 to sqrt(n)+1
								  // because if n is divisble by any value 
								  // in between it is not a prime 
	
		
		
		if (isDivisibleBy( n, counter)){ // check if any of the counter values is divides n cleanly. 
						
		
			prime = false; // if n is divisible cleanly, it is not prime, thus boolean prime is false.
			break; 
		}
		
	}
	

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

int countPrimes(int a, int b){
// function outputs the int value of the number of prime integers between a and b, inclusively. 

	int totalprimes, currentprime;

	currentprime = a - 1; // stored int currentprime as a minus 1 to have a starting point 

	totalprimes = 0; // tracks total amount of primes in between a and b


	while (nextPrime(currentprime) <= b){ //loops while the next highest prime number is less than n

	totalprimes++; // if the next prime is within interval, it adds 1 to the total prime counter
	
	currentprime = nextPrime(currentprime); 
	// sets new current prime starting point as the next prime higher than the previous starting point

	}

	return totalprimes;


} // end of countPrimes



bool isTwinPrime(int n){
//returns true if int n is a twin prime, false otherwise
	if ( (isPrime(n) == false) or (n < 3)) { // under the condition n is not prime, or is less than 3, it is 
						 // not a twin prime, thus false.

		return false;		

	}
	
	if ( (isPrime(n+2)) or (isPrime(n-2)) ){ // if either 2 more or 2 less of int n is prime then it is 
						 // a twin prime, thus true

		return true;

	}

} // end of isTwinPrime( int n)



int nextTwinPrime (int n){
// returns the int value of the next highest twin prime from int n
	
	int TwinPrime = nextPrime(n); // tracks the value of each prime greater than n in order
	
	while (isTwinPrime(TwinPrime) == false){ /* if the next prime is not a twin prime, it'll 
							go on to the next prime value, until a twin 								prime is found*/

		TwinPrime = nextPrime(TwinPrime);		
	
		}	
	return TwinPrime;


}  // end of nextTwinPrime ( int n )


int largestTwinPrime(int a, int b){
	
	int twinprime = a - 1 ; //twinprime starting point at a77

	if (nextTwinPrime(twinprime) > b){ //  returns -1 if next twin prime isn't in interval of a and b inclusive
		return -1;
	}

	else{
		
		for (int counter = b; ;counter--){

			if (isTwinPrime(counter)){

			twinprime = counter;
			break;

			}

		}
		
	/*while (nextTwinPrime(twinprime) <= b){ /* as long as the next twin prime is within interval, keeps 
							checking for the next twin prime. if it goes outside the
							interval, returns the previous twin prime. */
	
	//		twinprime = nextTwinPrime(twinprime);

	//	}
		return twinprime;


	}

} // end of largestTwinPrime(int a, int b)



int main(){
	
	int firstnum, secnum;
	// creates int value to store the user input 

	cout << "Enter an integer: ";
	cin >> firstnum;
	// stores the first user input as the int firstnum

	cout << "Enter an integer: ";
	cin >> secnum;
	// stores the second user input as the int firstnum

	cout << largestTwinPrime(firstnum, secnum) << endl; 


	
} // end of main()







