/*
Author: Sunniyatul Quaderin
Course: CSCI-135
Instructor: 
Assignment: Project 2 Pronounce


This program parses takes an user inputted word and returns to the user
the proper pronunciation of the word, the words that sound identical to 
the inputted word, words that can be formed by adding one phoneme, words that 
can be formed by removing on phoneme, and words that can be formed by replacing one 
phoneme. 

*/


#include <iostream>
#include <fstream>
#include <string>



using namespace std;


string SpaceSplitter(string s, int num);
string FormatInput(string aninput);

bool CheckForWord(string part, string whole);
int CountWords(string word);
bool PhonemeDifference(string original, string comparison, string num);
bool Phoneme(string original, string comparison);
bool ReplacePhoneme (string original, string comparison);


string FormatInput(string aninput){
//formats userinput to all caps so it can be searched for 

	string finalstring = "";
	
	if ((isalpha(aninput[0])) or (aninput[0] == '\'')){					//only continue to format if the string is an actual dictionary word
 
		for (int i = 0; i < aninput.size(); i++){
			finalstring += toupper(aninput[i]);

			if (isdigit(aninput[i])){						// force a not found since the input has a number 
				finalstring = "";
				break;	
			}

		}
	
	}

	return finalstring;
}






string SpaceSplitter(string s, int num) {
// Splits a string from the first space and returns the string before the space if num is 0. Return the string after the space if num is 1.
	
	string actualword = ""; 
	string wordpronunciation = "";

	
	int i = 0;
	while (i < s.size() && not isspace(s[i])) { actualword += s[i]; i++; }
	
	i++;
	
 	
	while ( (i < s.size()) and isspace(s[i])){

		i++;				
		
	}

	while (i < s.size()) { wordpronunciation += s[i]; i++; }

	if (num == 1){

		return wordpronunciation;
	}
	
	if (num == 0){
	
		return actualword;

	}

}




bool Phoneme(string original, string comparison){
// returns true if the comparison string is the original string plus a phoneme in any position
	
	bool outcome = false;

	if (CountWords(comparison) - CountWords(original) == 1){

		string firstcomparison = SpaceSplitter(comparison, 0);
		string  lastcomparison = SpaceSplitter(comparison, 1);
		string  lastlastcomparison = SpaceSplitter(lastcomparison, 1);
		string  firstlastcomparison = SpaceSplitter(lastcomparison, 0);

		string test = lastcomparison;
		
		
			if (test == original){
				outcome = true;
			}
			
			



			else{
				while (!lastcomparison.empty()){
				// checks different combinations of the comparison string excluding one phoneme to check if it equals the original string


					test = firstcomparison + " " + lastlastcomparison;			

					if (test == original){
						outcome = true;
						break;
					}
	
					if (firstcomparison == original){
						outcome = true;
						break;
					}

					// reset values to a different combination to compare to the original string 
					firstcomparison = firstcomparison + " " + firstlastcomparison;		
					lastcomparison = lastlastcomparison;
					lastlastcomparison = SpaceSplitter(lastcomparison, 1);
					firstlastcomparison = SpaceSplitter(lastcomparison, 0);


				}

			
				
				 

			}
				
			
		
		
			
		
		
		return outcome;

		
		


	}
	
	else{

	return outcome;
	
	}


}


bool ReplacePhoneme (string original, string comparison){
// checks to see if the original string has only one phoneme difference compared to the comparison string 
		
	int differencecount = 0;				// tracks the number of differentphonemes between the two strings

	if  (CountWords(original) == CountWords(comparison)) {

		string firstcomparison = SpaceSplitter(comparison, 0);
		string  lastcomparison = SpaceSplitter(comparison, 1);

		string  firstoriginal = SpaceSplitter(original, 0);
		string  lastoriginal = SpaceSplitter(original, 1);
		
		while(!firstoriginal.empty()){
		// compares each respective phoneme from original string and comparison string to check for differences.
		
			if (firstcomparison != firstoriginal){
			
				differencecount++;
			}
			
			firstcomparison = SpaceSplitter(lastcomparison, 0);
			lastcomparison = SpaceSplitter(lastcomparison, 1);
			
			firstoriginal = SpaceSplitter(lastoriginal, 0);
			lastoriginal = SpaceSplitter(lastoriginal, 1);
			
		}
	
		if (differencecount == 1){
			return true;
		}
		
		else{
			return false;
		}
		

	}
	else{
	
		return false;
	
	}




}










int CountWords(string word){
// counts the number of phonemes in a string 

	if (word.empty()){

		return 0;

	}
	
	else{
		int wordphonemecount = 1;
		char space = ' ';
		for (int i = 0; i < word.size() - 1;i++){
	
			if (word[i] == space and word[i+1] != space){
		
				wordphonemecount++;	
		
			}

		}
		return wordphonemecount;
	}

}












int main(){

	string before = "";
	string after = "";


	string Pronunciation = "";				// store the Pronounciation of the user inputted string
	string MainWord = "";					// store the userinputted word
	string Identical = ""; 					// stores words with the same pronunciation as MainWord 
	string AdderPhoneme = "";				// stores the words that can be arranged by adding one phoneme from the MainWord
	string RemovePhoneme = "";				// stores the words that can be arranged by removing one phoneme from the MainWord
	string ReplacerPhoneme = ""; 				// stroes the words that can be arranged by replacing one phoneme from the MainWord

	
	

	string word;
	ifstream Dictionary;
	Dictionary.open("cmudict.0.7a");


	string userinput;
	cin >> userinput;
	userinput = FormatInput(userinput);



	if (!Dictionary){ 
	
		cerr << "Unable to open file";
		
	}



	while (getline(Dictionary,word)){ 
	
		before = SpaceSplitter(word,0);
		after = SpaceSplitter(word, 1);
		
		if (before == userinput){	
			MainWord = before;
			Pronunciation = after;
		}
	}

	Dictionary.close();
	
	// only continue to output results the the format of the user input is acceptable as a dictionary term 
	if (MainWord != ""){				

		
		Dictionary.open("cmudict.0.7a");

	
		
		while (getline(Dictionary,word)){ 
		
			
			before = SpaceSplitter(word,0);
			after = SpaceSplitter(word, 1);

			// store the words that have identical pronunciation as the mainword
			if ((after == Pronunciation) and (before != MainWord)){	 		
	
				Identical  += before + " ";
	
			}
		
			// store the words that can be created by adding one phoneme to the mainword
			if (Phoneme(Pronunciation, after) and !(FormatInput(before)).empty()) {
	
				AdderPhoneme += before + " ";

			}

			// store the words that can be created by removing one phoneme from the mainword			
			if (Phoneme(after, Pronunciation) and !(FormatInput(before)).empty()){
	
				RemovePhoneme += before + " ";

			}

			// store the words that can be created by replacing one phoneme from the mainword
			if (ReplacePhoneme(Pronunciation, after) and !(FormatInput(before)).empty()){
	
				ReplacerPhoneme += before + " ";

			}
			
			


		}
		

		
		

	

		// Output the results of the word search 

		cout << "Pronunciation		: " << Pronunciation << endl;
		cout << endl;
		cout << "Identical		: " << Identical << endl;	 
		cout << "Add phoneme		: " << AdderPhoneme << endl;
		cout << "Remove phoneme	: " << RemovePhoneme << endl;
		cout << "Replace phoneme	: " << ReplacerPhoneme << endl;

	}

	else{

		cout << "Not Found" << endl;

	}



} 

































 
