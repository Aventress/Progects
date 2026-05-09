#pragma once

class Movie {
private:
	std::string name;
	size_t rating;
	size_t watched_count{};
	std::string description;
public:
	Movie(std::string name, std::string description, size_t rating, size_t watched_count);
	~Movie();

	Movie(const Movie& source);

	void set_name(std::string name);
	std::string get_name() const;

	void set_rating(size_t rating);
	size_t get_rating() const;

	void set_watched_count(size_t watched_count);
	size_t get_watched_count() const;

	void set_description(std::string desciption);
	std::string get_description() const;
};