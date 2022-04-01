/*

Name: Sunniyatul Quaderin
Course: CSCI 136
Assignment: LAB 11 D

This program will dynamically create a Poem using pointers 

*/


#include <iostream>



using namespace std;

string * createAPoemDynamically() {
// creates the poem string dynamically 
    string *p = new string;
    *p = "Roses are red, violets are blue";
    return p;
}

int main() {
    while(true) {
        string *p;
        p = createAPoemDynamically();
	delete p;			// free up memory since it's not needed any more
    }
	return 0;
}
