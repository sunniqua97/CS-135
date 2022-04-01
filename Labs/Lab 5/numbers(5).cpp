/*
Author: Sunniyatul Quaderin
Course: CSCI-136
Instructor: Gwanael Gatto
Assignment: Lab 5[F] Numbers


This program will ask the user to input an integer value and will determine 
the least twin prime greater than the inputted integer value. It will then output such value. 

ex:

Enter an integer: 6

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
	
	int nextTwinPrime = nextPrime(n); // tracks the value of each prime greater than n in order
	
	while (isTwinPrime(nextTwinPrime) == false){ /* if the next prime is not a twin prime, it'll 
							go on to the next prime value, until a twin 								prime is found*/

		nextTwinPrime = nextPrime(nextTwinPrime);		
	
		}	
	return nextTwinPrime;


}  // end of nextTwinPrime ( int n )



int main(){
	
	int firstnum;
	// creates int value to store the user input 

	cout << "Enter an integer: ";
	cin >> firstnum;
	// stores the first user input as the int firstnum

	cout << nextTwinPrime(firstnum) << endl;

	
	
} // end of main()







