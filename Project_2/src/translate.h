#ifndef TRANSLATE_H
#define TRANSLATE_H


#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <bitset>


using namespace std;

class translate {

private:
	string messageString;	//input message from file
	string divisorString;	//input divisor(polynomial) from file 

public:

	translate();	//default constructor
	void readInputFile(ifstream &input, ofstream &output);	//reads the input file
	void generateOutput(ofstream &output);

};

#endif 
