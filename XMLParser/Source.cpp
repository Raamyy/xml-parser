#include<iostream>
#include "XMLParser.h"
#include <string>
using namespace std;

int main() {

	XMLParser parser("../Data.xml");
	auto data = parser.getData();
	data.print();
	parser.saveData("Test.xml");
	return 0;
}