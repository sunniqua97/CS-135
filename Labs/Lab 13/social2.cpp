/*

Name: Sunniyatul Quaderin
Course: CSCI 136
Instructor: Gwenael Gatto
Assignment: LAB 13 B

This program will demonstate a simple classification of a Profile object 
We assign user names and full names for each Profile created

PART B

Performs more profile related actions such as user creation as well as name checks 




*/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool isAlphanumeric(string input){
	// recursive function to determine whether a string contains only alphanumeric values
	if (input.size() == 1){
		if (isalpha(input[0]) or isdigit(input[0])){
			return true;
		}
		else{
			return false;
		}
	}
	
	else{
		
		return isAlphanumeric(input.substr(0,1)) and isAlphanumeric(input.substr(1));
		
	}
	
	
}

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

class Network{
	
	private: 
		static const int MAX_USERS = 20; 
		int UserCount;                   
		Profile profiles[MAX_USERS];     
		
		int findID (string name){
			int usernamefound = -1;
			for(int current = 0; current < UserCount; current++){
				if(profiles[current].getUsername() == name){
					usernamefound = current;
				}
			}
			return usernamefound;
		}
		
	public:
	
		Network(){
			UserCount = 0;
		}
		
		bool addUser(string name, string full){
			
			if((UserCount >= MAX_USERS) or (name.length() < 1) or  (not isAlphanumeric(name))){
				
				return false;
			
			}
			
			for(int i = 0; i < UserCount; i++){
				
				if(profiles[i].getUsername() == name){
					
					return false;
				
				}
			}
			
			
			
			profiles[UserCount] = Profile(name, full);
			UserCount += 1;
			return true;
		}
	
};
	




int main(){
	/*
    Profile p1("marco", "Marco");
    cout << p1.getUsername() << endl; 
    cout << p1.getFullName() << endl; 

    p1.setDisplayName("Marco Rossi");
    cout << p1.getUsername() << endl; 
    cout << p1.getFullName() << endl; 

    Profile p2("tarma1", "Tarma Roving");
    cout << p2.getUsername() << endl; 
    cout << p2.getFullName() << endl;
	*/
	
	Network nw;
    cout << nw.addUser("mario", "Mario") << endl;     // true (1)
    cout << nw.addUser("luigi", "Luigi") << endl;     // true (1)

    cout << nw.addUser("mario", "Mario2") << endl;    // false (0)
    cout << nw.addUser("mario 2", "Mario2") << endl;  // false (0)
    cout << nw.addUser("mario-2", "Mario2") << endl;  // false (0)

    for(int i = 2; i < 20; i++)
        cout << nw.addUser("mario" + to_string(i), 
                   "Mario" + to_string(i)) << endl;   // true (1)

    cout << nw.addUser("yoshi", "Yoshi") << endl;     // false (0)

	
}