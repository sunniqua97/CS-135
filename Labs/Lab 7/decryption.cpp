/*
Author: Sunniyatul Quaderin
Course: CSCI-136
Instructor: Gwanael Gatto
Assignment: Lab 7[D] Vigenere


This program will demonstrate the Caesar and Vigenere cyphers to the user 
and then decrypt the user inputted values. 

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


string encryptVigenere(string plaintext, string keyword){		// applies shiftChar to each character in the string plaintext
	
	string finalstring = "";
	int rotation = 0;						// tracks the char position in rshift 

	
	
	for (int i = 0; i < plaintext.length(); i++){
	
		if (isalpha(plaintext[i])){				// shifts the char only if alphabetic
	
			finalstring += shiftChar(plaintext[i], (((int)(keyword[rotation % keyword.length()])))%97);
			rotation ++;
		}
		else{							// if not, just adds the char to the final output string

			finalstring += plaintext[i];		

		}

	}
	
	return finalstring;

} // end of encryptVigenere


string decryptCaesar(string ciphertext, int rshift){

	return encryptCaesar(ciphertext, (26 - (rshift%26)));


}

string decryptVigenere(string plaintext, string keyword){

	string finalstring = "";
	int rotation = 0;						// tracks the char position in rshift 

	
	
	for (int i = 0; i < plaintext.length(); i++){
	
		if (isalpha(plaintext[i])){				// shifts the char only if alphabetic
			int chartoint = (((int)(keyword[rotation % keyword.length()])))%97 ;
			finalstring += shiftChar(plaintext[i], (26 - chartoint));
			rotation ++;
		}
		else{							// if not, just adds the char to the final output string

			finalstring += plaintext[i];		

		}

	}
	
	return finalstring;


}


int main(){
	
	// Ceasar Cipher Test

	string userchar;					
	getline(cin,userchar);


	int usershiftint;					
	cin >> usershiftint;
	
	
	string caesaroutput = encryptCaesar(userchar, usershiftint);

	cout << caesaroutput << endl;

	cout << decryptCaesar(caesaroutput, usershiftint) << endl;

	
	

	// Vigenere Cipher Test

	string usershift;
	cin >> usershift;
	cout << encryptVigenere(userchar, usershift) <<  endl;
	cout << decryptVigenere(encryptVigenere(userchar, usershift), usershift) << endl;




} // end of main
 
