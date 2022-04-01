/*

Name: Sunniyatul Quaderin
Course: CSCI 136
Assignment: LAB 11 A

This program will output the distance of the coordinates 
from the origin. 


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
double length(Coord3D *p);


int main(){
    return 0;
}


double length(Coord3D *p){
// uses distance formula to calculate distance from origin
    double output = sqrt(((*p).x * (*p).x) + ((*p).y * (*p).y) + ((*p).z * (*p).z));
    return output;

  
}

