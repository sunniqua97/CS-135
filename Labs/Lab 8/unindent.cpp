/*
Author: Sunniyatul Quaderin
Course: CSCI-135
Instructor: Gwanael Gatto
Assignment: Lab 8[A] Unindent


This program unindents each input the user inputs in the terminal 
as well as removing any leading spaces. 

*/


#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;


string removeLeadingSpaces (string line);
int countChar(string line, char c);


int main(){
	string line;

	
	while(getline(cin, line))
	{
		cout << removeLeadingSpaces(line)<< endl;
	}
	

}
		


string removeLeadingSpaces (string line){		//removes all leading spaces from string
	int begindex = 0;
	int endindex = line.length()-1;			
	string finalstring = "";
	for (int i = endindex; i >= 0 ;i--)		// finds the end of string excluding spaces
	{
		if (!isspace(line[i]))
		{
			endindex = i;
			break;
		}
	}
	
	for (int j = 0; j <= endindex ;j++)		// finds the beginning of a string excluding spcaes
	{
		if (!isspace(line[j]))
		{
			begindex = j;
			break;
		}
	}

	for (int k = begindex; k <= endindex ;k++)	// uses the prior values of beginning index and end  to return the string without leading spaces
	{
		finalstring += line[k];
	}


	return finalstring;

}




