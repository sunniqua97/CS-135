/*
Author: Sunniyatul Quaderin
Course: CSCI-135
Instructor: Gennadiy Maryash
Assignment: Project1D[Calc3]


This program will read a text file with multiple addition 
subtraction sequences and return the total of each sequence on each line.
Each sequence is seperated by a semicolon.
Also it is able to recognize the square symbol (^) and squares a number like 
5^ to represent it correctly as 25 in the sequence of operations and add or subtract it
from the total.

ex: ./sum < textexample.txt contains:

5^ + 45 - 10^;
3^ + 2^ ;

will return:

-30
13


*/


#include <iostream> 
#include <cstdlib> // required to use the atoi function to convert number strings to int


using namespace std;

bool checkforsquared(string numbr){
	// function checks a numbr string to check if the number contains the ^ character
	// it will return true if it must be squared, and false if it doens't
	
	bool isitsquared = false; // isitsqured will track whether a number should be 
				  // squared (true) or not (false). initially set to 
				  // false to assume its not squared. 
	
	int numbrlen = numbr.length(); // stores the length of the string numbr
	
	
	for (int parser = 0; parser < numbrlen; parser++){
	//check if the number should be squared
	// by parsing through the numbr string to look for the '^' symbol
	
		if (numbr[parser] == '^'){
			isitsquared = true; // if its find the ^ symbol in the numbr 
					    // string, its sets isitsqured to true to 
					    // signify the number should be squared

		} // end of if (numbr[parser] == '^')

	} // end of for (int parser = 0; parser < numbrlen; parser++)

	return isitsquared;
	// returns the boolean isitsquared to show whether the number should be squared

} // end of checkforsquared(string numbr)

int squareit(string numb, bool squared){

	if(squared){
	// if squared value is true symbolized the numb string should be squared

	int x = numb.length() - 1;
	// checks length of the numb string

	string numbwithoutsymbol = numb.substr(0,x);
	// sets the numbwithoutsymbol string to a string excluding the ^ symbol 
	// in the numb string

	int numbernotsquared = atoi(numbwithoutsymbol.c_str());
	// converts the string numbwithout symbol to the int value numbernotsquared

	return numbernotsquared * numbernotsquared;
	// squares numbernotsquared and returns it


	} // end of if(squared)

	else{

		return atoi(numb.c_str());
		// if the boolean squared is false, the numb doesn't need to be squared
		// so this returns the value of the numb as an int. 
	
	} // end of else statement 

} // end of squareit(string numb, bool squared)





int addorsubtract(bool operation, int totalsum, string numba){
// this function would determine whether or not a number should be added or subtracted
// from the total of the equation. then it appropriately adds or subtracts it from the 
// total.
	
	bool squared = checkforsquared(numba);
	// sets the boolean squared to true if the string numba needs to be squared
	// false if not

	int num = squareit(numba,squared);
	// returns the square of the value of the string numb as an int and stores it
	// as int num, fi the squared boolean is true. if not it'll return the numba 
	// string as an int without squaring it
		

			if (operation){
			// checks whether or not the boolean value operation is true,
			// so the int num may be added to the current total (totalsum) of 
			// the equation. 

				totalsum = totalsum + num;

			// if the operation value is false, the int num will be
			// added to the current total (totalsum) of the equation.

			} // end of if(operation)
				
			else{
				totalsum = totalsum - num;

			// if the operation value is false, the int num will be
			// subtracted to the current total (totalsum) of the equation.

			} // end of else statement 
			
	return totalsum;
	// returns the current total (totalsum) of the equation

} // end of addorsubtract(bool operation, int totalsum, string numba)


int main(){

	char wordornum; // wordornum will represent every character in the text file

	int total = 0;  // represents the total of the equation

	bool addit = true;	// represents whether a value should be added (true) or 
				// subtracted (false). Set to true initially to account 
				//for the inevitable addition of the first value. 

	string number; // stores the string version of an identified number
	



	
	while(cin >> wordornum){ // reads through every character in the text file and 
				 // represents it as wordornum. Stops parsing when there 
				// is no more char values to represent
		
		number += wordornum; 	
		// adds the current char value to the number string so it may be
		// later converted to an int value 
		

		

		if(wordornum == '+'){ 	// checks if the current wordornum char is a 
					// symbol for addition

		
		total = addorsubtract(addit, total, number);
		// converts the stored number to an int and adds or subtracts from the
		// total 

		addit = true; 	
		
		// sets the boolean addit to true so the next number given 
		// is added 
		
		number = "";

		// resets the number string to an empty string so we may store the 
		// next number value 


		}// end of if(wordornum == '+')

		if(wordornum == '-'){	// checks if the current wordornum char is a 
					// symbol for subtraction
		
		total = addorsubtract(addit, total, number);
		// converts the stored number to an int and adds or subtracts from the
		// total 

		addit = false;

		// sets the boolean addit to true so the next number given 
		// is added 

		number = "";

		// resets the number string to an empty string so we may store the 
		// next number value



		} // end of if(wordornum == '-')

		if(wordornum == ';'){       // checks if the current wordornum char is a
				       // semicolon so we may move on to the next equation

			total = addorsubtract(addit, total, number);
			// converts the stored number to an int and adds or subtracts
			// from the total 

				
			cout << total << endl;
			// outputs the total for the equation ending with a semicolon

			total = 0;
			// resets the total value to 0 to track the total for the
			// equation after the semicolon

			number = ""; 
			// resets the number string to an empty string so we may store 
			//the next number value

			addit = true;
			// set to true because you must add the first number term to the  
			// total either way
		
		} // end of if(wordornum == ';')
				
	} // end of while (cin >> wordnum)
	


} // end of int main
