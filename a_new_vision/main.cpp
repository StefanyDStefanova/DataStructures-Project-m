#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include "skip_list.h"
#include "skip_list.cpp"

int main()
{
	std::cout << "Number of cities through which the passenger train passes: ";
	int numOfCity;
	std::cin >> numOfCity;

	SkipList<std::string> listWithCitys;
	std::string city;

	std::cout << "The names of the cities: ";

	// add citys in queue 

	for (int i = 0; i < numOfCity; i++)
	{
		std::cin >> city;
		listWithCitys.insertElem(city);
	}

	std::cout << "Write how many direct links there are: ";
	int maxDirectLinks;
	std::cin >> maxDirectLinks;

	if (maxDirectLinks > 0)
	{
		std::cout << "Write direct links: ";
		std::string city1, city2;

		for (int i = 0; i < maxDirectLinks; i++)
		{
			std::cin >> city1 >> city2;

			listWithCitys.connect(city1, city2);
		}
	}


	std::cout << "List of cities of Anya and Vankata: ";
	std::cout <<std::endl<< "*if you press sybol point you will stop typing."<<std::endl;

	std::queue<std::string> citiesOfAnyaAndVankata;
	std::string line;

	while (true)
	{
		std::cin >> line;
		if (line == ".")
			break;
		citiesOfAnyaAndVankata.push(line);
	}

	// search way
	listWithCitys.wayForAnyaAndVankata(citiesOfAnyaAndVankata);

	return 0;
}
