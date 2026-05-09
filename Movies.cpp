#include "iostream"
#include "Movies.h"
#include "Movie.h"
#include <string>

void Movies::add_movie(std::string nam, std::string descr, size_t rat, size_t wat_count) { // add movie to collection
	Movie movie_1 (nam, descr, rat, wat_count);
	movies.push_back(movie_1);
	for (const auto& movie : movies) {
		if (movie.get_name() == movie_1.get_name()) {
			std::cout << "Film already exist"; //TODO: later add display information about exising film
			movies.pop_back();
		}
	} 
}