/*
Author: Sunniyatul Quaderin
Course: CSCI-136
Instructor: Gwanael Gatto
Assignment: Lab 7[C] Vigenere


This program will implement the Vigenere cipher. 
It'll ask the user to input a sentence and a string word indicating
how much the letters in the sentence should be shifted by for each char in the word. 
The letters are shifted by the ascii value of each char value, but doesn't shift any 
non-alphabetic characters. 
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


string encryptVigenere(string plaintext, string rshift){		// applies shiftChar to each character in the string plaintext
	
	string finalstring = "";
	int rotation = 0;						// tracks the char position in rshift 

	
	
	for (int i = 0; i < plaintext.length(); i++){
	
		if (isalpha(plaintext[i])){				// shifts the char only if alphabetic
	
			finalstring += shiftChar(plaintext[i], (((int)(rshift[rotation % rshift.length()])))%97);
			rotation ++;
		}
		else{							// if not, just adds the char to the final output string

			finalstring += plaintext[i];		

		}

	}
	
	return finalstring;

} // end of encryptVigenere




int main(){

	string userchar;					//recieves user sentence input including spaces
	getline(cin,userchar);

	string usershift;						// recieves user shift int input
	getline(cin, usershift);
	
	cout << encryptVigenere(userchar, usershift);




} // end of main
 
