#include "translate.h"

using namespace std;

translate::translate() {

}

void translate::readInputFile(ifstream &input, ofstream &output) {
	string entireOutput = "";
	for (string line; getline(input, line); ) {
		entireOutput += line + "\n";
	}
	ofstream outputFile;
	outputFile.open("output.txt");
	outputFile << entireOutput;
	outputFile.close();
}

void translate::generateOutput(ofstream &output) {

}