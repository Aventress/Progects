#include <iostream>
#include <string>
#include <cstdlib>
#include <limits> //для numeric limits
#include "Movies.h"

int main() {
	Movies movies_list;
	std::string name, descriprion;
	size_t rating{}, watched_count{};
	size_t menu_choice{0};
	
	do {
		std::cout << "Movie collecton\n Enter your choice: \n1. Add Movie\n2. Show all Movies in collection\n3. Increace watched count" << std::endl;
		std::cin >> menu_choice;
		switch (menu_choice) {
		case 1:
			system("cls");
			std::cout << "Add Movie: \nEnter Movie name: ";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::getline(std::cin, name);
			std::cout << "\nEnter Movie descryption (leave hollow, if you want): ";
			std::getline(std::cin, descriprion);
			if (descriprion.size() == NULL) {
				descriprion = "...";
			}
			std::cout << "\nEnter Movie rating: ";
			std::cin >> rating;
			std::cout << "\nEnter how many times did you watched movie: ";
			std::cin >> watched_count;
			movies_list.add_movie(name, descriprion, rating, watched_count);
			continue;
		case 2:
			system("cls");
			movies_list.display_movies();
			continue;
		case 3:
			system("cls");
			if (!movies_list.get_empty()) {
				int number_to_increase{};
				std::cout << "Enter name of the Movie you would like to increace the number of view of.\n Also, here's all Movies in the collection: \n";
				movies_list.display_movies();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::getline(std::cin, name);
				std::cout << "And number of times is: ";
				std::cin >> number_to_increase;
				movies_list.add_watch_count(name, number_to_increase);
			}
			else {
				std::cout << "bro, create film first\n";
			}
			continue;
		}
	} while (menu_choice != 9);
	return 0;
}