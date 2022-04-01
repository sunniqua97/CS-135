/*

Author: Sunniyatul Quaderin
Course: CSCI-135
Instructor: Gennadi Maryash
Assignment: Project 3

This program will simulate the debris by robots 
in space. The goal is for the robots to be able to clean up
the debris in a timely manner, as well as provide neccesary 
repairs to other robots that may malfunction. 


*/


#include <cstdlib>
#include <iostream>
#include "bot.h"
#include <cmath>


using namespace std;

double DistanceFromPoint(int id, int row, int col, Area &area);
int SurroundingDebris(int row, int col, Area &area);
bool IsThereNoRobotThere(int row, int col, Area &area);
bool closestRobot(int id, int row, int col, Area &area);
Action PreferredMove(int row, int col, int crow, int ccol, Area &area);
Action GoTowardsRobot(int id, int id2, Area &area, Loc loc, ostream &log);
Loc NearestDebris(int id, Area &area);


const int MAX_ROBOT_NUM = 50;

int NUM;          // to remember number or robots
int ROWS, COLS;   // map dimensions


int Malfunction[50];	// create an array of int values for malfunctions
			// if a value is equal to -2, a robot is malfunctioning


/* Initialization procedure, called when the game starts: */
void onStart(int num, int rows, int cols, double mpr,
             Area &area, ostream &log)
{
	NUM = num;   // save the number of robots and the map dimensions
	ROWS = rows;
	COLS = cols;

	for (int i = 0; i < 50; i++){

	
		Malfunction[i] = -1;	// Set all values in the array as -1 to indicate normal function
	
	
	}
	
	
	

	log << "Start!" << endl;

	
}



double DistanceFromPoint(int id, int row, int col, Area &area){
// gives the distance from a robots location (id) to a row, col location

	double difrow = (area.locate(id).r - row) * (area.locate(id).r - row);
	double difcol = (area.locate(id).c - col) * (area.locate(id).c - col) ; 
	double output = sqrt( difrow + difcol);
	return output;
}



int SurroundingDebris(int row, int col, Area &area){
// returns the number of debris surrounding a point

	int numofdebris;
	for (int i = row - 1; (i <= row + 1) and (i < ROWS) ; i++){
		for (int k = col - 1; (k <= col + 1) and (k < COLS); k++){
						
			if(area.inspect(i,k) == DEBRIS){
				numofdebris++;
			}
		
		}
	}
	return numofdebris;
	

}

bool IsThereNoRobotThere(int row, int col, Area &area){
// checks to see if there's a robot in a spot, if not prints true. 
	bool norobothere = true;
	
	if (row < 0 or col < 0 or row > ROWS or col > COLS){
		
		norobothere = false;		

	}
	
	else{
		for( int i = 0; i < NUM; i++ ){
		
			if ((area.locate(i).r == row) and (area.locate(i).c == col)) {
		
				norobothere = false;

			}
	
		}
	}
		
	return norobothere;

}

bool closestRobot(int id, int row, int col, Area &area){
// determines if current robot is closest to a point (debris, malfunctioning robot) in row, col
	
	bool trulyclosest = true;
	double origdist = DistanceFromPoint( id , row, col, area);
	
			

	// parse though every robot id 
	for( int i = 0; i < NUM; i++ ){
		if ( i == id){

			// do nothing since its the current robot
		}
		
		else if (Malfunction[i] == -2){
		
			// ignore those results too 
	
		}
		else{
			double compdist = DistanceFromPoint( i , row, col, area);
			if ( compdist < origdist ){
				trulyclosest = false;
							
			}
		}
	}
	return trulyclosest;
}





Action PreferredMove(int row, int col, int crow, int ccol, Area &area){   

// direct traffic of other robots in the way as well as going towards debris 
		
		
		bool right = IsThereNoRobotThere(row, col + 1, area);
		bool left = IsThereNoRobotThere(row, col - 1, area);
		bool up = IsThereNoRobotThere(row - 1, col, area);
		bool down = IsThereNoRobotThere(row + 1, col, area);
		
	
		// command directions to go 
		if (row > crow){
			
			if(up){
			return UP;			
			}
			else if (right){
			return RIGHT;
			}
			else if (left){
			return LEFT;
			}
			else if(down){
			return DOWN;
			}
			
		}

		else if (row < crow){
			if(down){
			return DOWN;
			}
			else if (left){
			return LEFT;
			}
			else if (right){
			return RIGHT;
			}
			else if(up){
			return UP;
			}			

		}

		else if (col > ccol){
			if(left){
			return LEFT;
			}
			else if (up){
			return UP;
			}
			else if(down){
			return DOWN;
			}
			
			else if (right){
			return RIGHT;
			}
		}
		
		else{
			if(right){
			return RIGHT;
			}
			
			else if(down){
			return DOWN;
			}
			
			else if (up){
			return UP;
			}
			else if (left){
			return LEFT;
			}
		}
	
}



Action GoTowardsRobot(int id, int id2, Area &area, Loc loc, ostream &log){  
// goes towards the id robot, which is most likely malfunctioning  

		int crow = area.locate(id).r;
		int ccol = area.locate(id).c;
		
		int row = area.locate(id2).r;
		int col = area.locate(id2).c;
		
		// if it's next to you, repair it
		// mark repaired robots back to normal
		// mark the repairer back to normal
		
		bool robotabove = (row - 1 == crow) and (col == ccol);
		bool robotbelow = (row + 1 == crow) and (col == ccol);
		bool robotright = (col + 1 == ccol) and (row == crow);
		bool robotleft = (col - 1 == ccol) and (row == crow);

		if (robotabove){
			Malfunction[id] = -1;
			Malfunction[id2] = -1;
			return REPAIR_UP;
			
		}
		else if(robotbelow){
			Malfunction[id] = -1;
			Malfunction[id2] = -1;
			return REPAIR_DOWN;
		}
		else if(robotright){
			Malfunction[id] = -1;
			Malfunction[id2] = -1;
			return REPAIR_RIGHT;
		}
		else if(robotleft){
			Malfunction[id] = -1;
			Malfunction[id2] = -1;		
			return REPAIR_LEFT;
		}
		else{
		// if not close enough move closer to it
			return PreferredMove(row, col, crow, ccol, area);
		}
		
}




Loc NearestDebris(int id, Area &area){
// finds the best debris to target
	
	Loc Nearest;
	double debrisdistance = 100;
	int crow = -1;
	int ccol = -1;
	int currentSurroundingDebris = -1;

	// the most optimal debris to go after is the closest to the robot exclusively
	for(int i = 0; i < ROWS; i++){
		for(int k = 0; k < COLS; k++){
			if(area.inspect(i,k) == DEBRIS){			
				if ((DistanceFromPoint(id, i, k, area) < debrisdistance) and closestRobot(id, i, k, area)){
								
					debrisdistance = DistanceFromPoint(id, i, k, area);
					crow = i;					
					ccol = k;
								
				}
			}
		}
	}

	if(crow == -1){
	
	// if the first optimal point isn't available, go towards the debris with the most surrounding debris and closest
		currentSurroundingDebris = -1;
		debrisdistance = 100;
		for(int i = 0; i < ROWS; i++){
			for(int k = 0; k < COLS; k++){
				if(area.inspect(i,k) == DEBRIS){			
					if (((DistanceFromPoint(id, i, k, area) < debrisdistance) and (SurroundingDebris(i,k,area) > currentSurroundingDebris) )){
						
						currentSurroundingDebris = SurroundingDebris(i,k,area);
						debrisdistance = DistanceFromPoint(id, i, k, area);
						crow = i;					
						ccol = k;
								
					}
				}
			}
		}
	


	}
	
	
	Nearest.r = crow;
	Nearest.c = ccol;
	return Nearest;
}

/* Deciding robot's next move */
Action onRobotAction(int id, Loc loc, Area &area, ostream &log) {

	int row = loc.r; // current row and column
	int col = loc.c;
	
	
	if (Malfunction[id] >= 0){
	// a robot focused on fixing another robot 

		return GoTowardsRobot(Malfunction[id], id, area, loc, log);		
	}	
	
	
	else if (area.inspect(row,col) == DEBRIS){
		return COLLECT;
	}

	
	else {

		for (int i = 0; i < 50; i++){
				
			// Find one malfunctioning 
			if ( Malfunction[i] == -2 ){
			
				// check if you're the closest to it
				if (closestRobot(id, area.locate(i).r , area.locate(i).c , area)){

					// focus on the malfunctioning robot, don't pick up debris.	
					Malfunction[id] = i;
					return GoTowardsRobot(Malfunction[id], id, area, loc, log);		
				
				}
			
			}

		}
		

		// find the nearest (best) debris to target

		Loc nearest = NearestDebris(id, area);
	
		// make moves towards it 

		return PreferredMove(row, col, nearest.r, nearest.c, area);
	}
		
		
		
}




void onRobotMalfunction(int id, Loc loc, Area &area, ostream &log) {
// executes whenever a robot malfunctions 

	log << "Robot " << id << " is damaged." << endl;
	
	// Mark the id of the current robot as malfunctioning 
	Malfunction[id] = -2;

}

void onClockTick(int time, ostream &log) {
	if (time % 100 == 0) log << time << " ";
}

 


