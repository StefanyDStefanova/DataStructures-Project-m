#include <iostream>
#include <stdexcept>

#include "mapGraph.h"

int main()
{
	std::ifstream in("GraphCityMap.txt", std::ios::in);

	if (!in.is_open())
	{
		std::cout << "File cannot be opened!" << std::endl;
		return -1;
	}

	Graph<int, std::string> g;
	g=g.createMap("GraphCityMap.txt");

	
	in.close();

	return 0;
}
