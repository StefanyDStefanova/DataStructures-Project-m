#include <iostream>

#include "mapGraph.h"

int main()
{
	std::string fileName;
	std::cout << "Filename: ";
	std::cin >> fileName;

	Graph<int, std::string>	createMap(fileName);

	return 0;
}