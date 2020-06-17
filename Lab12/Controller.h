#pragma once
#include "Repository.h"
#include "Comparator.h"
#include "Comps.h"
#include "WatchList.h"
#include "FIleWatchList.h"
#include "MovieValidator.h"
#include <vector>
#include "ActionStack.h"
#include "Action.h"

class Controller
{
private:
	Repository& repo;
    FileWatchList* watchlist;
	MovieValidator validator;
	ActionStack stack;

public:
	Controller(Repository& r, FileWatchList* watchlist, MovieValidator validator) : repo(r), watchlist(watchlist), validator(validator) {}

	// Returns the repository
	Repository& getRepo() const { return repo; }
	
	// Returns the watchlist
	WatchList getWatchlist() const { return *watchlist; }

	/* Adds a movie with the given data to the movie repository.
	Input: title, genre, year, likes, trailer - movie information
	Output: true - if the movie as added 
			false - otherwise
	*/
	void addMovieToRepository(const std::string& title, const std::string& genre, int year,int likes, const std::string& trailer);

	/* Removes the movie with the given title from the movie repository.
		Input: the title of the movie to be removed
		Output: true - if the movie was successfully removed
				false - otherwise
	*/
	void deleteMovieFromRepository(const std::string& title);

	/* Updates a movie's information with the given data in the movie repository.
	Input: title, genre, year, likes, trailer - movie information
	Output : true - if the movie as added
			false - otherwise
	*/
	void updateMovieInRepository(const std::string& title, const std::string& genre, int year, int likes, const std::string& trailer);

	/*
	Returns the movie with the given title
	Input: the title
	Output: the movie
	*/
	Movie getMovieFromRepository(const std::string& title);


	/*
		Adds a given movie to the watchlist.
		Input: movie - Movie, the movie must belong to the repository.
		Output: the movie is added to the watchlist.
	*/
	void addMovieToWatchlist(const Movie& movie);

	/* Removes the movie with the given title from the watchlist.
	Input: the title of the movie to be removed
	Output: true - if the movie was successfully removed
	false - otherwise
	*/
	void deleteMovieFromWatchlist(const std::string& title);

	void saveWatchlistToFile();
	void openWatchlist();
	std::vector<Movie> getMoviesByGenre(const std::string& genre);
	void undo();
	void redo();

};

void sort(std::vector<Movie>& v, Comparator<Movie>* c);
