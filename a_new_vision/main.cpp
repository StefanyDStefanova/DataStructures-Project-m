#include <iostream>
#include <string>
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

	
	/*
	std::cout << "Write how many direct links there are: ";
	int maxDirectLinks;
	std::cin >> maxDirectLinks;

	std::vector<std::string> links;

	std::cout << "Direct links: ";	
	for (int i = 0; i < maxDirectLinks; i++)
	{
		std::getline(std::cin, city);
		links.push_back(city);
	}

	std::cout << "List of cities of Anya and Vankata: ";
	std::string citiesOfAnyaAndVankata;

	// da napylnim string s gradowete
	std::getline(std::cin, citiesOfAnyaAndVankata);

	// search way
	// wayForAnyaAndVankata(listWithCitys,citiesOfAnyaAndVankata);*/
	return 0;
}