#ifndef VARIABLE_H
#define VARIABLE_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class variable {

private:
	string name;
	bool signedOrNot;
	int width;

public:
	variable();	//default constructor
	variable(string name, bool signedOrNot, int width);
};

#endif 
