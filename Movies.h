#pragma once
#include "Movie.h"
#include <string>
#include <vector>

class Movies : public Movie{
private:
	std::vector <Movie> movies;
public:
	Movies();
	~Movies();

	void add_movie(std::string name, std::string description, size_t rating, size_t watched_count);
	void add_watch_count();
	void display_movies();
};