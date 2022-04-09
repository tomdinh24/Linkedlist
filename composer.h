#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;


class Composer {
public:
	string name;
	string dateOfDeath;

	Composer();
	Composer(string, string);
	int numberOfLines(ifstream&);

};
