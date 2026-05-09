#include "iostream"
#include "Movies.h"
#include "Movie.h"
#include <string>


Movies::Movies() {
}

Movies::~Movies() {
}

bool Movies::get_empty() const{
	return empty;
}

void Movies::set_empty() {
	empty = false;
}

void Movies::add_movie(std::string nam, std::string descr, size_t rat, size_t wat_count) { // add movie to collection
	Movie movie_1 (nam, descr, rat, wat_count);
	for (const auto& movie : movies) {
		if (movie.get_name() == nam) {
			std::cout << "Film " << movie.get_name() << " already exist in list" << std::endl; 
			return;
		}
	}	
	movies.push_back(movie_1);
	set_empty();
}

void Movies::add_watch_count(std::string movie_name, int increase_count) {
	for (auto& movie_1 : movies) {
		if (movie_1.get_name() == movie_name) {
			movie_1.set_watched_count(movie_1.get_watched_count() + increase_count);
			if (movie_1.get_watched_count() < 0) {
				std::cout << "bro, something wrong with your math, let me set watch count to 0\n";
				movie_1.set_watched_count(0);
			}
			std::cout << "Currently, watched count for movie " << movie_1.get_name() << " = " << movie_1.get_watched_count() << std::endl;
			return;
		}
	}
	std::cout << "Movie " << movie_name << " don't exist, create it first" << std::endl;
}

void Movies::display_movies() {
	if (movies.empty()) {
		std::cout << "Current collection is empty((\n";
	} else {
		std::cout << "Current Movie List: \n";
		for (const auto& movie_1 : movies) {
			std::cout << movie_1.get_name()
				<< "\nAnd it's about: " << movie_1.get_description()
				<< "\nWith your rating of: " << movie_1.get_rating()
				<< "\nAnd you've watched it: " << movie_1.get_watched_count()
				<< " times\n";
			std::cout << "=================================================\n";
		}
	}
} 