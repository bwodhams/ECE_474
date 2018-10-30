// Oscar Functions
/*
 The convertTypes function takes in a string as a parameter. This string is a line.
 The line can be either an input output wire or register. The function will then
 convert this line into verilog and return it as a string. This function calls 
 addVariable that will add the variable to a vector according to the type (input, 
 output, wire, or register) 
 
Example:  
input string  -> input Int64 a, b, c
output string -> input [int64-1:0] a, b, c

The function will work for inputs, outputs, wires and registers. To use it just 
copy and paste in specific order. - Oscar
*/

vector<variable> inputVariables;
vector<variable> outputVariables;
vector<variable> wireVariables;
vector<variable> registerVariables;

void addVariables(string type, string name, bool isSigned, int width) {

	if (type.compare("input ") == 0) {  //if variable is an input, add to inputVariables vector
		variable var = variable(name, isSigned, width);
		inputVariables.push_back(var);
	}

	else if (type.compare("output ") == 0) {  //if variable is an output, add to outputVariables vector
		variable var = variable(name, isSigned, width);
		outputVariables.push_back(var);
	}

	else if (type.compare("wire ") == 0) {  //if variable is an wire, add to wireVariables vector
		variable var = variable(name, isSigned, width);
		wireVariables.push_back(var);
	}

	else if (type.compare("register ") == 0) {  //if variable is an register, add to registerVariables vector
		variable var = variable(name, isSigned, width);
		registerVariables.push_back(var);
	}

}

string convertTypes(string line) {
	string inString = line;
	string outString = "";
	string splitterVar = ", ";
	
	//1 BIT
	if ((line.find("Int1") != string::npos) && !(line.find("Int16") != string::npos)) {

		// UNSIGNED INPUT
		if (line.find("UInt1") != string::npos) {
			//truncate up to UInt1
			string splitterSize = "UInt1 ";
			outString += inString.substr(0, inString.find(splitterSize)); // outstring = "input | output | wire"
			string temp = outString;
			inString.erase(0, inString.find(splitterSize) + splitterSize.length());
			//outString += "[Uint1-1:0] "; // no need because these are 1 bit variables
			outString += inString;
			//look for the variables
			unsigned int pos = 0;
			string token;
			while ((pos = inString.find(splitterVar)) != string::npos) {
				token = inString.substr(0, pos);
				addVariables(temp, token, false, 1);
				inString.erase(0, pos + splitterVar.length());
			}
			addVariables(temp, inString, false, 1);
		}
		//SIGNED INPUTS
		else {
			//truncate up to Int1
			string splitterSize = "Int1 ";
			outString += inString.substr(0, inString.find(splitterSize)); // outstring = "input | output | wire"
			string temp = outString;
			inString.erase(0, inString.find(splitterSize) + splitterSize.length());
			//outString += "[Uint1-1:0] "; // no need because these are 1 bit variables
			outString += inString;
			//look for the variables
			unsigned int pos = 0;
			string token;
			while ((pos = inString.find(splitterVar)) != string::npos) {
				token = inString.substr(0, pos);
				addVariables(temp, token, true, 1);
				inString.erase(0, pos + splitterVar.length());
			}
			addVariables(temp, inString, true, 1);
		}
	}
	
	// 2 BIT
	else if (line.find("Int2") != string::npos) {

		// UNSIGNED INPUT
		if (line.find("UInt2") != string::npos) {
			//truncate up to UInt2
			string splitterSize = "UInt2 ";
			outString += inString.substr(0, inString.find(splitterSize)); // outstring = "input | output | wire"
			string temp = outString;
			inString.erase(0, inString.find(splitterSize) + splitterSize.length());
			outString += "[Uint2-1:0] "; // no need because these are 1 bit variables
			outString += inString;
			//look for the variables
			unsigned int pos = 0;
			string token;
			while ((pos = inString.find(splitterVar)) != string::npos) {
				token = inString.substr(0, pos);
				addVariables(temp, token, false, 2);
				inString.erase(0, pos + splitterVar.length());
			}
			addVariables(temp, inString, false, 2);
		}
		//SIGNED INPUTS
		else {
			//truncate up to Int2
			string splitterSize = "Int2 ";
			outString += inString.substr(0, inString.find(splitterSize)); // outstring = "input | output | wire"
			string temp = outString;
			inString.erase(0, inString.find(splitterSize) + splitterSize.length());
			outString += "[Int2-1:0] ";
			outString += inString;
			//look for the variables
			unsigned int pos = 0;
			string token;
			while ((pos = inString.find(splitterVar)) != string::npos) {
				token = inString.substr(0, pos);
				addVariables(temp, token, true, 2);
				inString.erase(0, pos + splitterVar.length());
			}
			addVariables(temp, inString, true, 2);
		}
	}

	//8 BIT
	else if (line.find("Int8") != string::npos) {

		// UNSIGNED INPUT
		if (line.find("UInt8") != string::npos) {
			//truncate up to UInt8
			string splitterSize = "UInt8 ";
			outString += inString.substr(0, inString.find(splitterSize)); // outstring = "input | output | wire"
			string temp = outString;
			inString.erase(0, inString.find(splitterSize) + splitterSize.length());
			outString += "[Uint8-1:0] ";
			outString += inString;
			//look for the variables
			unsigned int pos = 0;
			string token;
			while ((pos = inString.find(splitterVar)) != string::npos) {
				token = inString.substr(0, pos);
				addVariables(temp, token, false, 8);
				inString.erase(0, pos + splitterVar.length());
			}
			addVariables(temp, inString, false, 8);
		}
		//SIGNED INPUTS
		else {
			//truncate up to Int8
			string splitterSize = "Int8 ";
			outString += inString.substr(0, inString.find(splitterSize)); // outstring = "input | output | wire"
			string temp = outString;
			inString.erase(0, inString.find(splitterSize) + splitterSize.length());
			outString += "[Int8-1:0] ";
			outString += inString;
			//look for the variables
			unsigned int pos = 0;
			string token;
			while ((pos = inString.find(splitterVar)) != string::npos) {
				token = inString.substr(0, pos);
				addVariables(temp, token, true, 8);
				inString.erase(0, pos + splitterVar.length());
			}
			addVariables(temp, inString, true, 8);
		}
	}

	//16 BIT
	else if (line.find("Int16") != string::npos) {

		// UNSIGNED INPUT
		if (line.find("UInt16") != string::npos) {
			//truncate up to UInt16
			string splitterSize = "UInt16 ";
			outString += inString.substr(0, inString.find(splitterSize)); // outstring = "input | output | wire"
			string temp = outString;
			inString.erase(0, inString.find(splitterSize) + splitterSize.length());
			outString += "[Uint16-1:0] ";
			outString += inString;
			//look for the variables
			unsigned int pos = 0;
			string token;
			while ((pos = inString.find(splitterVar)) != string::npos) {
				token = inString.substr(0, pos);
				addVariables(temp, token, false, 16);
				inString.erase(0, pos + splitterVar.length());
			}
			addVariables(temp, inString, false, 16);
		}
		//SIGNED INPUTS
		else {
			//truncate up to Int16
			string splitterSize = "Int16 ";
			outString += inString.substr(0, inString.find(splitterSize)); // outstring = "input | output | wire"
			string temp = outString;
			inString.erase(0, inString.find(splitterSize) + splitterSize.length());
			outString += "[Int16-1:0] ";
			outString += inString;
			//look for the variables
			unsigned int pos = 0;
			string token;
			while ((pos = inString.find(splitterVar)) != string::npos) {
				token = inString.substr(0, pos);
				addVariables(temp, token, true, 16);
				inString.erase(0, pos + splitterVar.length());
			}
			addVariables(temp, inString, true, 16);
		}
	}

	//32 BIT
	else if (line.find("Int32") != string::npos) {
		// UNSIGNED INPUT
		if (line.find("UInt32") != string::npos) {
			//truncate up to UInt32
			string splitterSize = "UInt32 ";
			outString += inString.substr(0, inString.find(splitterSize)); // outstring = "input | output | wire"
			string temp = outString;
			inString.erase(0, inString.find(splitterSize) + splitterSize.length());
			outString += "[Uint32-1:0] ";
			outString += inString;
			//look for the variables
			unsigned int pos = 0;
			string token;
			while ((pos = inString.find(splitterVar)) != string::npos) {
				token = inString.substr(0, pos);
				addVariables(temp, token, false, 32);
				inString.erase(0, pos + splitterVar.length());
			}
			addVariables(temp, inString, false, 32);
		}
		//SIGNED INPUTS
		else {
			//truncate up to Int32
			string splitterSize = "Int32 ";
			outString += inString.substr(0, inString.find(splitterSize)); // outstring = "input | output | wire"
			string temp = outString;
			inString.erase(0, inString.find(splitterSize) + splitterSize.length());
			outString += "[Int32-1:0] ";
			outString += inString;
			//look for the variables
			unsigned int pos = 0;
			string token;
			while ((pos = inString.find(splitterVar)) != string::npos) {
				token = inString.substr(0, pos);
				addVariables(temp, token, true, 32);
				inString.erase(0, pos + splitterVar.length());
			}
			addVariables(temp, inString, true, 32);
		}
	}
	
	//64 BIT
	else if (line.find("Int64") != string::npos) {

		// UNSIGNED INPUT
		if (line.find("UInt64") != string::npos) {
			//truncate up to UInt64
			string splitterSize = "UInt64 ";
			outString += inString.substr(0, inString.find(splitterSize)); // outstring = "input | output | wire"
			string temp = outString;
			inString.erase(0, inString.find(splitterSize) + splitterSize.length());
			outString += "[Uint64-1:0] ";
			outString += inString;
			//look for the variables
			unsigned int pos = 0;
			string token;
			while ((pos = inString.find(splitterVar)) != string::npos) {
				token = inString.substr(0, pos);
				addVariables(temp, token, false, 64);
				inString.erase(0, pos + splitterVar.length());
			}
			addVariables(temp, inString, false, 64);
		}
		//SIGNED INPUTS
		else {
			//truncate up to Int64
			string splitterSize = "Int64 ";
			outString += inString.substr(0, inString.find(splitterSize)); // outstring = "input | output | wire"
			string temp = outString;
			inString.erase(0, inString.find(splitterSize) + splitterSize.length());
			outString += "[Int64-1:0] ";
			outString += inString;
			//look for the variables
			unsigned int pos = 0;
			string token;
			while ((pos = inString.find(splitterVar)) != string::npos) {
				token = inString.substr(0, pos);
				addVariables(temp, token, true, 64);
				inString.erase(0, pos + splitterVar.length());
			}
			addVariables(temp, inString, true, 64);
		}
	}
	return outString;
}