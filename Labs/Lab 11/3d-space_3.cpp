/*

Name: Sunniyatul Quaderin
Course: CSCI 136
Assignment: LAB 11 C

This program will shift the coordinates inputted by a certain amount. 



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


void move(Coord3D *pp, Coord3D *pv, double dub) {

	// shift the points 
	(*pp).x = (*pp).x + (*pv).x * dub;
	(*pp).y = (*pp).y + (*pv).y * dub;
	(*pp).z = (*pp).z + (*pv).z * dub;

}


int main(){
    return 0;
}




