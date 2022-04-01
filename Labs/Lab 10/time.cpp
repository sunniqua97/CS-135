/*

Author: Sunniyatul Quaderin
Course: CSCI-136
Instructor: Gwenael Gatto
Assignment: Lab 10 A (time.cpp)

This program will implement two functions ( minutesSinceMidnight(Time time), 
minutesUntil (Time earlier, Time later) ). The first function will take a struct 
input of Time, and return the minutes from midnight (0:00am) as an int.
The second function will take two Time structs and return the difference in minutes 
between both as an int.  

*/

#include <iostream>
using namespace std;

struct Time{
// stores hours and min to represent time	

	int hours;
	int min;
};


int minutesSinceMidnight(Time time);
int minutesUntil(Time earlier, Time later);

int main(){



}

int minutesSinceMidnight(Time time){
// returns the time passed from midnight until time. 

	int diffhours = time.hours - 0;
	int diffmin = time.min - 0;
	
	int midnightdiff = (diffhours * 60) + diffmin;
	return midnightdiff;


}

int minutesUntil(Time earlier, Time later){
// returns difference in later and earlier as minutes
// returns negative if the later is before earlier. 

	int untilhours = later.hours - earlier.hours;
	int untilmin = later.min - earlier.min;

	int untildiff = untilhours * 60 + untilmin;


}
