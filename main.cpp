#include <iostream>
#include <string>
#include <vector>
#include "Skip_list.h"

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
		listWithCitys.insertLast(city);
	}

	std::cout << "Direct links: ";
	// add skip points in queue
	// dokato kakwo?
	/*while (true)
	{
		// da wywejda skip neshata
	}*/

	std::cout << "List of cities of Anya and Vankata: ";
	std::string citiesOfAnyaAndVankata;

	// da napylnim string s gradowete
	std::getline(std::cin, citiesOfAnyaAndVankata);

	// search way
	// wayForAnyaAndVankata(listWithCitys,citiesOfAnyaAndVankata);
	return 0;
}
