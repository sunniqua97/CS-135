
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




	string date;
	double eastSt, eastEl, westSt, westEl,maximum, minimum;
	maximum = 0; 
	minimum = 80; 
	
	

	

	while (fin >> date >> eastSt >> eastEl >> westSt >> westEl) {

		if (eastSt > maximum){
			maximum = eastSt;
			
		}
		if (eastSt < minimum){
			minimum = eastSt;
		}
		
		
	}
	
	cout << "minimum storage in East basin: " << minimum << " billion gallons" << endl;
	cout << "MAXimum storage in East basin: " << maximum << " billion gallons" << endl;


	
	fin.close();
	return 0;
} //main

