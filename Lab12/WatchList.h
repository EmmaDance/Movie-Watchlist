#pragma once
#include <vector>
#include "Movie.h"

class WatchList
{
protected:
	std::vector<Movie> movies;
	int current;
public:
	WatchList();
	
	//Returns a Dynamic Vector of Movies 
	std::vector<Movie> getMovies() const { return movies; }

	// Adds a movie to the watchlist.
	void addMovie(const Movie& m);

	/*
	Deletes a movie from the watchlist
	Input: m - the movie to be deleted
	Output: true - if the movie m was succesfully deleted
			false - otherwise
	*/
	void deleteMovie(Movie & m);

	/*
	Returns the movie with the given title from the watchlist 
	Input: title - the title of the movie 
	Output: the movie 
	*/
	Movie getMovie(const std::string & title);

	/* Checks if the playlist is empty.
	   Input: -
	   Output: true - if the watchlist is empty
	        false - otherwise
	*/
	bool isEmpty();
	bool exists(Movie& m);

};

