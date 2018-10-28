#include "variable.h"

using namespace std;

variable::variable() {

}

variable::variable(string name, bool signedOrNot, int width) {
	this->name = name;
	this->signedOrNot = signedOrNot;
	this->width = width;
}

