#include "iostream"
#include "Movies.h"
#include "Movie.h"
#include <string>


Movies::Movies() {
}

Movies::~Movies() {
}

void Movies::add_movie(std::string nam, std::string descr, size_t rat, size_t wat_count) { // add movie to collection
	Movie movie_1 (nam, descr, rat, wat_count);
	movies.push_back(movie_1);
	for (const auto& movie : movies) {
		if (movie.get_name() == movie_1.get_name()) {
			std::cout << "Film already exist" << std::endl; //TODO: later add display information about exising film
			movies.pop_back();
		}
	} 
}

void Movies::add_watch_count(std::string movie_name) {
	for (auto& movie_1 : movies) {
		if (movie_1.get_name() == movie_name) {
			movie_1.set_watched_count(movie_1.get_watched_count() + 1);
			std::cout << "Currently, watched count for movie " << movie_1.get_name() << " = " << movie_1.get_watched_count() << std::endl;
		}
		else {
			std::cout << "Movie " << movie_1.get_name() << " don't exist, create it first" << std::endl;
		}
	}
}

void Movies::display_movies() {
	std::cout << "Current Movie List" << std::endl;
	for (const auto& movie_1 : movies) {
		std::cout << movie_1.get_name() << " " << movie_1.get_description() << " " << movie_1.get_rating() << " " << movie_1.get_watched_count() << std::endl;
	}
} /*это кстати странный момент, вроде как Фрирен уже один раз разбивала Ауру и она помнит Фрирен, но тем не менее она все равно решила посоревноваться в количестве маны*/