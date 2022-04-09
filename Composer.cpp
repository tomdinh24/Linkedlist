#include <iostream>
#include <fstream>
#include <iomanip>
#include "composer.h"
#include <string>
#include<cstdlib>
using namespace std;

//Default Constructor
Composer::Composer() {
	name = "";
	dateOfDeath = "";
}

//Overloaded Constructor 
Composer::Composer(string n, string date) {
	name = n;
	dateOfDeath = date;

}

//Receives the file
//Function: count the amount of lines in the file
int Composer::numberOfLines(ifstream& inFile) {
	int count = 0;
	string size;

	while (getline(inFile, size)) {
		count++;
	}
	inFile.clear();
	inFile.seekg(0);
	return count;
}
