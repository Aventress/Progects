#include <iostream>
#include <iomanip>
#include <vector>
#include <string>


//Challenge 1
struct City {
	std::string name;
	long population;
	double fly_cost;
};

struct Country {
	std::string name;
	std::vector<City> cities;
};

struct Tours {
	std::string title;
	std::vector<Country> countries;
};

void ruller() {
	std::cout << "1234567890";
}

size_t calculate_ruller_middle(size_t ruller_size) {
	return ruller_size - (ruller_size - 1) / 2;
}

int main()
{
	size_t ruller_size;
	size_t ruller_middle;
	size_t ruller_parts;
	std::string hello{ "Hellofgjdjetkktyf" };
	Tours tours
	{ "Tours From Gugu Gaga",
		{
			{
				"Poland", {
					{"Warshawa", 200000, 180},
					{"Gdansk", 300000, 160},
					{"Krakov", 100000, 120}
				},
			},
			{
				"Russia", {
					{"Moskow", 1000000, 200},
					{"Samara", 200000, 300},
					{"Rostov", 1000000000, 0}
				},
			},
			{
				"China", {
					{"Pekin", 10000000, 10},
					{"Shanhai",10000000, 20},
					{"Uzbek", 20, 1}
				}
			},
			{
				"Zube Dube",{
					{"Uga Buga", 40, 1234432},
					{"Duga Muga", 5, 999}
				}
			}
		}
	};

	std::cout << "enter a ruller size: ";
	std::cin >> ruller_size;
	for (int i = 0; i != ruller_size; i++) {
		ruller();
	}
	std::cout << std::endl;

	ruller_middle = calculate_ruller_middle(ruller_size);
	ruller_parts = ruller_size * 10 / 4;

	std::cout << std::setfill('-') << std::setw(10 * ruller_middle) << tours.title << std::setw(10*ruller_size - 10 * ruller_middle + 1) << " " << std::endl;
	std::cout << std::setfill(' ');
	//std::cout << std::setprecision(10);
	std::cout << std::fixed << std::setprecision(0);
	for (Country country: tours.countries) {
		for (size_t i = 0; i < country.cities.size(); ++i) {
			std::cout << std::setw(ruller_parts) << std::left << ((i == 0) ? country.name : "")
				<< std::setw(ruller_parts) << std::left << country.cities.at(i).name
				<< std::setw(ruller_parts) << std::left << country.cities.at(i).population
				<< std::setw(ruller_parts) << std::left << country.cities.at(i).fly_cost << std::endl;
		}
	}
	std::cout << std::resetiosflags(std::ios::floatfield); //reset flags
	std::cout << std::endl << std::endl;
	return 0;
}