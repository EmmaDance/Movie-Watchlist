#pragma once
#include "Controller.h"
#include "Iterator.h"
#include <string>
#include "MovieValidator.h"

class UI
{
private:
	Controller c;

public:
	UI(const Controller& c) : c(c) {}

	void start();

private:
	static void printMenu();
	static void printAdminMenu();
	static void printUserMenu();
	static void printMovie(const Movie& m);
	static void printSubmenu();
	void addMovieToRepo();
	void deleteMovieFromRepo();
	void updateMovieInRepo();
	void displayAllMoviesRepo();
	void seeMovies();
	void seeWatchlist();
	Movie deleteMovieFromWatch();
	void rateMovie(Movie& m);
	void saveWatchlist();
	void displayWatchlist();
};