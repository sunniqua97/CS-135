/*
Author: Sunniyatul Quaderin
Course: CSCI-135
Instructor: Gennadiy Maryash
Assignment: Project1C[Calc2]


This program will read a text file with multiple addition 
subtraction sequences and return the total of each sequence on each line.
Each sequence is seperated by a semicolon

ex: ./sum < textexample.txt contains:

-7 + 9 - 45;
1 + 4-3;

will return:

-43
2


*/


#include <iostream> 
#include <cstdlib> // required to use the atoi function to convert number strings to int



using namespace std;


int addorsubtract(bool operation, int totalsum, string numba){ 
// this function would determine whether or not a number should be added or subtracted
// from the total of the equation. then it appropriately adds or subtracts it from the 
// total.
	
	int num = atoi(numba.c_str());
	// converts string number input and converts it to an int number value 
	// so it may be added or subtracted. stored as the value num. 
		

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

} // end of addorsubtract


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
				
	} // end of while(cin >> wordornum) loop
	


} // end of int main 
