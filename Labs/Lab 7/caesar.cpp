/*
Author: Sunniyatul Quaderin
Course: CSCI-136
Instructor: Gwanael Gatto
Assignment: Lab 7[B] Ceasar


This program will implement the Ceaser cipher. 
It'll ask the user to input a sentence and a number indicating
how much the letters in the sentence should be shifted by. 
Then it will return the resulting sentence. 

 */

#include <iostream>

using namespace std;


char shiftChar(char c, int rshift){			//shifts a character by rshift
	int shift;
	int finalcharint;


	if (!isalpha(c)){				// checks to see if the character is not alphabetic 
	
		finalcharint = (int)c;

	}
	
	else if ( (int)c < 91){					// shifts the letter if uppercase

		shift = ((((int)c % 65) + (rshift % 26)) % 26);		
		finalcharint = 65 + shift;
	
	}
	
	else{							// shifts the letter if capitalized
	
		shift = ((((int)c % 97) + (rshift % 26)) % 26);
		finalcharint = 97 + shift;
	}

	

	char finalchar = (char)finalcharint;
	return finalcharint;

} // end of shiftChar


string encryptCaesar(string plaintext, int rshift){		// applies shiftChar to each character in the string plaintext 
	
	string finalstring = "";

	
	
	for (int i = 0; i < plaintext.length(); i++){

		finalstring += shiftChar(plaintext[i], rshift);

	}
	
	return finalstring;

} // end of encrypt Caesar




int main(){

	string userchar;					//recieves user sentence input including spaces
	getline(cin,userchar);

	int usershift;						// recieves user shift int input
	cin >> usershift;
	
	cout << encryptCaesar(userchar, usershift);




} // end of main
 
