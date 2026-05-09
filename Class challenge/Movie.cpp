#include <iostream>
#include "Movie.h"

Movie::Movie(std::string name, std::string description, size_t rating, size_t watched_count)
	:name(name), description(description), rating (rating), watched_count(watched_count) {
}
Movie::~Movie(){ }

Movie::Movie(const Movie& source) 
	:Movie{source.name, source.description, source.rating, source.watched_count} {

}

void Movie::set_name(std::string n) { name = n; }
std::string Movie::get_name() const { return name; }

void Movie::set_rating(size_t rati) { rating = rati; }
size_t Movie::get_rating() const { return rating; }

void Movie::set_watched_count(size_t count) { watched_count = count; }
size_t Movie::get_watched_count() const { return watched_count; }

void Movie::set_description(std::string desc) { description = desc; }
std::string Movie::get_description() const { return description; }

