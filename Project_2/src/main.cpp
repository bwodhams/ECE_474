#include "translate.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {

	translate mainThread;
	ifstream inputFile;
	//inputFile.open(argv[1]);
	inputFile.open("c1.txt");
	ofstream outputFile;
	outputFile.open("output.txt");

	if (inputFile.is_open() && outputFile.is_open()) {


		mainThread.readInputFile(inputFile, outputFile);

		inputFile.close();
		outputFile.close();
	}

	cin.get();


	return 0;

}