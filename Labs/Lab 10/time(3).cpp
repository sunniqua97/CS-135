/*

Author: Sunniyatul Quaderin
Course: CSCI-136
Instructor: Gwenael Gatto
Assignment: Lab 10 C (time.cpp)

Part A

This program will implement two functions ( minutesSinceMidnight(Time time), 
minutesUntil (Time earlier, Time later) ). The first function will take a struct 
input of Time, and return the minutes from midnight (0:00am) as an int.
The second function will take two Time structs and return the difference in minutes 
between both as an int.  

Part B

This program will also implement (Time addMinutes(Time time0, int min)) function to return 
the resulting Time time0, after min minutes. 

Part C

Additionally, this program will return the information from an inputted timeslot, including ending time, 
using the function void printTimeSlot(TimeSlot ts);. 

Part D 

This program will also implement the function TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie);
which will return the Timeslot of the next movie. 


*/

#include <iostream>
using namespace std;

struct Time{
// stores hours and min to represent time	

	int hours;
	int min;
};

enum Genre {ACTION, COMEDY, DRAMA, ROMANCE, THRILLER};

struct Movie {
    string title;
    Genre genre;     // only one genre per movie
    int duration;    // in minutes
};

struct TimeSlot {
    Movie movie;     // what movie
    Time startTime;  // when it starts
};


int minutesSinceMidnight(Time time);
int minutesUntil(Time earlier, Time later);
Time addMinutes(Time time0, int min);
void printTimeSlot(TimeSlot ts);
void printMovie(Movie mv);
TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie);


int main(){

	Time morning, daytime, evening;
	

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

Time addMinutes(Time time0, int min){
// will return Time struct min minutes after time0

	time0.min = time0.min + min;
	time0.hours += time0.min / 60;
	time0.min = time0.min % 60;


	return time0;
}

void printTimeSlot(TimeSlot ts){
// will formally return information from TimeSlot ts

	Time endtime = addMinutes(ts.startTime, ts.movie.duration);
	printMovie(ts.movie) ;
	cout << "  [starts at " << ts.startTime.hours << ":" <<  ts.startTime.min << ", ends by " << endtime.hours <<":" << endtime.min << "]";


}

void printMovie(Movie mv){
// will properly format and print information regard a Movie mv. 
    string g;
    switch (mv.genre) {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }
    cout << mv.title << " " << g << " (" << mv.duration << " min)";
}

TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie){
// will return the TimeSlot of the nextMovie assuming its scheduled immediately 
// after TimeSlot ts. 

	TimeSlot movie = ts;
	movie.movie = nextMovie;
	movie.startTime = addMinutes (ts.startTime, ts.movie.duration);
	return movie;


}


