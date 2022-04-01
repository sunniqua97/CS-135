/*
Author: Sunniyatul Quaderin
Course: CSCI-135
Instructor: Gwanael Gatto
Assignment: Project 8[B] Lab 8 INDENT


This program will take the users inputted strings 
and return the proper formated file string 
with correct indents 

*/


#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

string indent(int indentcount);
string removeLeadingSpaces (string line);
int countChar(string line, char c);

int main()
{
	string line;	

	int indentcounter = 0;

	
	while(getline(cin, line)){
		
		string newline = removeLeadingSpaces(line);
		
		if (newline[0] == '}'){
		    
            for(int i = 0; i < indentcounter-1; i++){
                
                cout << indent(1);
                
            }
		}
		else{
		    
		    for (int k = 0; k < indentcounter; k++){
		        
		        cout << indent (1);
		            
		    }
		    
		    
		}
        
        cout << newline << endl;
        indentcounter = indentcounter + countChar(newline,'{');
        indentcounter = indentcounter - countChar(newline,'}');
        
		
	}


}



string indent(int indentcount){						// indents file by a certain given number
	string finalstring = "";
	for (int y = 1; y <= indentcount; y++){
		finalstring +=  "	";
	}
	return finalstring;

}
		
int countChar(string line, char c)					// counts the number of a certain character in a line of string input
{
	int count = 0;
	for (int i = 0; i < line.size(); i++)
	{

		if (line[i] == c)
		{
			count++;
		}

	}
	return count;


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