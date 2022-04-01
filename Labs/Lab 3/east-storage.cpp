
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



	string userdate;
	cout << "Enter a date: ";
	cin >> userdate;




	string date;

	double eastSt, eastEl, westSt, westEl;

	while (fin >> date >> eastSt >> eastEl >> westSt >> westEl) {

		if (userdate == date) {
			cout << "East basin storage: " << eastSt << " billion gallons" << endl;
		}


	}

	fin.close();
	return 0;
} //main

