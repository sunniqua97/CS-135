/*

Name: Sunniyatul Quaderin
Course: CSCI 136
Instructor: Gwenael Gatto
Assignment: LAB 13 A

This program will demonstate a simple classification of a Profile object 
We assign user names and full names for each Profile created


*/

#include <iostream>
using namespace std;
class Profile{
	
	private:
		string user;
		string fullname;
		
	public:
		Profile(string name, string full){
			
			user = name;
			fullname = full;
		}
		
		Profile(){
			user = "";
			fullname = "";
			
		}
		string getUsername(){
		// returns the name of the user 
				return user;
		
		}
		
		string getFullName(){
		// Returns the name of the user in full with proper formatting 
			return fullname + " (@" + user + " )";
			
		}
		
		
		void setDisplayName(string full){
		// Function changes the name displayed 	
			fullname = full;
			
		}
		
		
};

int main(){
    Profile p1("marco", "Marco");
    cout << p1.getUsername() << endl; 
    cout << p1.getFullName() << endl; 

    p1.setDisplayName("Marco Rossi");
    cout << p1.getUsername() << endl; 
    cout << p1.getFullName() << endl; 

    Profile p2("tarma1", "Tarma Roving");
    cout << p2.getUsername() << endl; 
    cout << p2.getFullName() << endl;
}