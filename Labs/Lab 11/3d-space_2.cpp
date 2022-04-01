/*

Name: Sunniyatul Quaderin
Course: CSCI 136
Assignment: LAB 11 B

This program will output the coordinate furthest from the 
origin when comparing two. 



*/


#include <iostream>
#include <string>
#include <cmath>

using namespace std;


struct Coord3D{
        double x;
        double y;
        double z;
};


double length(Coord3D *p) {
	// uses distance formula to calculate distance from origin
	double output = sqrt(((*p).x * (*p).x) + ((*p).y * (*p).y) + ((*p).z * (*p).z));
	return output;


}


Coord3D * fartherFromOrigin(Coord3D *p1, Coord3D *p2) {
	// outputs the coordinate furthest from the origin

	if (length(p1) < length(p2)) {

		return p2;

	}
	else {

		return p1;

	}

}


int main(){
    return 0;
}




