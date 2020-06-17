#pragma once
#include "Movie.h"
#include <vector>

class Repository
{
private:
	std::vector<Movie> movies;
	std::string filename;
	void readFromFile();
	void writeToFile();

public:
	/*
		Default constructor.
	*/
	Repository() { filename = "movies.txt"; readFromFile(); }

	/*
	Constructor with filename.
	*/
	Repository(std::string filename) { 
		this->filename = filename; 
		this->readFromFile();
	}

	/*
		Adds a movie to the repository.
		Input: m - Movie.
		Output: the movie is added to the repository.
				returns true if it was added successfully
						false otherwise
	*/
	void addMovie(const Movie& m);

	/*
	Deletes a movie from the repository.
	Input: m - Movie.
	Output: the movie is deleted from the repository.
			returns true if it was deleted successfully
			false otherwise
	*/
	void deleteMovie(Movie& m);

	/*
	Updates a movie's information in the repository.
	Input: m - Movie.
	Output: the movie is updated
			returns true if it was updated successfully
			false otherwise
	*/
	void updateMovie(Movie& m);

	/*
	Returns the movie with the given title
	Input: the title
	Output: the movie
	*/
	Movie getMovie(const std::string& title);

	/*
	Returns a Dynamic Vector containing all the movies in the Repository
	*/
	const std::vector<Movie>& getMovies() const { return movies; }

	/*
	Clears both the in-memory and the file repository.
	*/
	void emptyRepo();

	/*
	Returns a vector of movies that have the given genre
	*/
	std::vector<Movie> getMoviesByGenre(const std::string & genre) const;

	/*
	Checks whether a movie exists in the repository
	Input: m - movie
	Output: true - if the movie is in te reository
			false - otherwise
	*/
	bool exists(Movie& m);


};