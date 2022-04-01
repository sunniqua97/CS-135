
#include <iostream> // cin, cout, cerr
#include <fstream> // ifstream
#include <cstdlib> // exit()


using namespace std;

int main() {
	// create file handle
	ifstream fin("Current_Reservoir_Levels.tsv");

	//Check if file can be opened
	if (fin.fail()) {
		cerr << "Cannot open file" << endl;
		exit(1);
	}

	string junk;        // new string variable
	getline(fin, junk); // read one line from the file



	string startinguserdate;
	cout << "Enter starting date: ";
	cin >> startinguserdate;
	
	string endinguserdate;
	cout << "Enter ending date: ";
	cin >> endinguserdate;
	
	




	string date;

	double eastSt, eastEl, westSt, westEl;
	
	bool withininterval;
	
	withininterval = false;
	
	

	while (fin >> date >> eastSt >> eastEl >> westSt >> westEl) {
	
		if (startinguserdate == date){
			withininterval = true;

		}
		
		
	
	
		if (withininterval){

		if (eastEl < westEl) {
			cout << date << " West" << endl;
		}
		
		if (eastEl > westEl) {
			cout << date << " East" << endl;
		}
		
		if (eastEl == westEl) {
			cout << date << " Equal" << endl;
		}
		
		if (endinguserdate == date){
			withininterval = false;
		}
		}
		



	}

	fin.close();
	return 0;
} //main

