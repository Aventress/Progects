#pragma once
#include "Movie.h"
#include <string>
#include <vector>

class Movies {
private:
	std::vector <Movie> movies;
	bool empty{true};
public:
	Movies();
	~Movies();

	bool get_empty() const;
	void set_empty();
	void add_movie(std::string name, std::string description, size_t rating, size_t watched_count);
	void add_watch_count(std::string name, int increace_count);
	void display_movies();
};