#include "translate.h"

using namespace std;

translate::translate() {

}
vector <string> allVars;
vector <string> allowedOperations{"=", "+", "-", ">", ">>", "<", "<<", "?", ":", "*"};
void translate::readInputFile(ifstream &input, ofstream &output) {
	string entireOutput = "";
	for (string line; getline(input, line); ) {
		//replace spaces in line with | to make things easier for parsing
		replace(line.begin(), line.end(), ' ', '|');
		//if line contains the word input, output, or wire, call output function to add the variables to the array of all variable names for error checking
		if ((line.find("input") != string::npos && line.find("|") == 5) || (line.find("output") != string::npos && line.find("|") == 6) || (line.find("wire") != string::npos && line.find("|") == 4)) {
			generateOutput(line);
		}
		else if(line.length() == 0) {
			
		}
		else {
			variableExists(line);
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

bool translate::variableExists(string inputLine) {
	int numSpaces = count(inputLine.begin(), inputLine.end(), '|');
	bool changedSpaces = false;
	if (inputLine.find("||") != string::npos) {
		numSpaces = numSpaces - 2;
		changedSpaces = true;
	}
	//Check to make sure second char in line is equal sign
	if (inputLine.substr(inputLine.find("|") + 1, 1) != "=") {
		cout << "no equal sign" << endl;
		return false;
	}
	if (numSpaces == 2) {
		for (int i = 0; i < numSpaces + 1; i++) {
			if (i == 1) {
				inputLine.erase(0, 2);
			}
			else if (i == 2) {
				if (changedSpaces == true) {
					if (find(allVars.begin(), allVars.end(), inputLine.substr(0, inputLine.find("|"))) != allVars.end()) {
						//Final var exists
					}
					else {
						cout << "error, " << inputLine << " doesn't exist" << endl;
					}
				}
				else {
					if (find(allVars.begin(), allVars.end(), inputLine.substr(0)) != allVars.end()) {
						//Final var exists
					}
					else {
						cout << "error, " << inputLine << " doesn't exist" << endl;
					}
				}

			}
			else if (find(allVars.begin(), allVars.end(), inputLine.substr(0, inputLine.find("|"))) != allVars.end()) {
				//Variable exists, no errors
				inputLine = inputLine.substr(inputLine.find("|"));
				inputLine.erase(0, 1);
			}
			else {
				cout << inputLine << "   has a variable that isn't defined prior" << endl;
				return false;
			}
		}
	}
	if (numSpaces == 4) {
		for (int i = 0; i < numSpaces + 1; i++) {
			if (i == 1) {
				inputLine.erase(0, 2);
			}
			else if (i == 3) {
				if (find(allowedOperations.begin(), allowedOperations.end(), inputLine.substr(0, inputLine.find("|"))) != allowedOperations.end()) {
					//Operation is valid
				}
				else {
					//Operation is invalid
					cout << "operation is invalid" << endl;
					return false;
				}
				inputLine.erase(0, 2);
			}
			else if (i == 4) {
				if (changedSpaces == true) {
					if (find(allVars.begin(), allVars.end(), inputLine.substr(0, inputLine.find("|"))) != allVars.end()) {
						//Final var exists
					}
					else {
						cout << "error, " << inputLine << " doesn't exist" << endl;
					}
				}
				else {
					if (find(allVars.begin(), allVars.end(), inputLine.substr(0)) != allVars.end()) {
						//Final var exists
					}
					else {
						cout << "error, " << inputLine << " doesn't exist" << endl;
					}
				}
				
			}
			else if (find(allVars.begin(), allVars.end(), inputLine.substr(0, inputLine.find("|"))) != allVars.end()) {
				//Variable exists, no errors
				inputLine = inputLine.substr(inputLine.find("|"));
				inputLine.erase(0, 1);
			}
			else {
				cout << inputLine << "   has a variable that isn't defined prior" << endl;
				return false;
			}
		}
	}
	
	if (numSpaces == 6) {
		for (int i = 0; i < numSpaces + 1; i++) {
			if (i == 1) {
				inputLine.erase(0, 2);
			}
			else if (i == 3) {
				if (find(allowedOperations.begin(), allowedOperations.end(), inputLine.substr(0, inputLine.find("|"))) != allowedOperations.end()) {
					//Operation is valid
				}
				else {
					//Operation is invalid
					cout << "operation is invalid" << endl;
					return false;
				}
				inputLine.erase(0, 2);
			}
			else if (i == 5) {
				if (find(allowedOperations.begin(), allowedOperations.end(), inputLine.substr(0, inputLine.find("|"))) != allowedOperations.end()) {
					//Operation is valid
				}
				else {
					//Operation is invalid
					cout << "operation is invalid" << endl;
					return false;
				}
				inputLine.erase(0, 2);
			}
			else if (i == 6) {
				if (find(allVars.begin(), allVars.end(), inputLine.substr(0)) != allVars.end()) {
					//Final var exists
				}
				else {
					cout << "error, " << inputLine << " doesn't exist" << endl;
				}
			}
			else if (find(allVars.begin(), allVars.end(), inputLine.substr(0, inputLine.find("|"))) != allVars.end()) {
				//Variable exists, no errors
				inputLine = inputLine.substr(inputLine.find("|"));
				inputLine.erase(0, 1);
			}
			else {
				cout << inputLine << "   has a variable that isn't defined prior" << endl;
				return false;
			}
		}
	}
	return true;
}