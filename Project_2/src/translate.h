#ifndef TRANSLATE_H
#define TRANSLATE_H


#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

class translate {

public:

	translate();	//default constructor
	void readInputFile(ifstream &input, ofstream &output);	//reads the input file
	string generateOutput(string inputLine);
	bool variableExists(string inputLine);

};

#endif 
