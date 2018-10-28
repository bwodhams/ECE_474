#include "translate.h"

using namespace std;

translate::translate() {

}
vector <string> allVars;
void translate::readInputFile(ifstream &input, ofstream &output) {
	string entireOutput = "";
	for (string line; getline(input, line); ) {
		//replace spaces in line with | to make things easier for parsing
		replace(line.begin(), line.end(), ' ', '|');
		//if line contains the word input, output, or wire, call output function to add the variables to the array of all variable names for error checking
		if ((line.find("input") != string::npos && line.find("|") == 5) || (line.find("output") != string::npos && line.find("|") == 6) || (line.find("wire") != string::npos && line.find("|") == 4)) {
			generateOutput(line);
		}
		else {
			generateOutput(line);
		}
		entireOutput += line + "\n";
	}
	ofstream outputFile;
	outputFile.open("output.txt");
	outputFile << entireOutput;
	outputFile.close();
	for (int i = 0; i < allVars.size(); i++) {
		cout << allVars[i] << endl;
	}
}

string translate::generateOutput(string inputLine) {
	//Create array with all defined variables for error checking
	if (inputLine.find("input") != string::npos || inputLine.find("output") != string::npos || inputLine.find("wire") != string::npos) {
		string tempString = inputLine.substr(inputLine.find("|"));
		tempString.erase(0, 1);
		tempString = tempString.substr(tempString.find("|"));
		tempString.erase(0, 1);
		while (tempString.length() != 0) {
			if (tempString.find(",") != string::npos) {
				allVars.push_back(tempString.substr(0, tempString.find(",")));
				tempString.erase(0, allVars[allVars.size() - 1].length() + 2);
			}
			else {
				allVars.push_back(tempString.substr(0));
				tempString = "";
			}
		}
	}
	
	return "asdf";
}