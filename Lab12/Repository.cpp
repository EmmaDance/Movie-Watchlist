#include "Repository.h"
#include "RepositoryExceptions.h"
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

void Repository::readFromFile()
{
	ifstream file(this->filename);
	if (!file.is_open())
		throw FileException("This file could not be opened.");
	Movie m;
	while (file >> m)
		this->movies.push_back(m);
	file.close();
}

void Repository::writeToFile()
{
	ofstream file(this->filename);
	if (!file.is_open())
		throw FileException("The file could not be opened");
	for (auto m : this->movies)
		file << m;
	file.close();
}

void Repository::addMovie(const Movie& m)
{
	if (find(this->movies.begin(), this->movies.end(), m) == this->movies.end()) {
		this->movies.push_back(m);
		writeToFile();
		return;
	}
	else
		throw DuplicateMovieException();
}

bool Repository::exists(Movie& m) {
	if (find(this->movies.begin(), this->movies.end(), m) == this->movies.end())
		return false;
	return true;

}

void Repository::deleteMovie(Movie & m)
{
	if (!this->exists(m))
		throw RepositoryException("There is no movie with this title in the repository.");
	this->movies.erase(find(this->movies.begin(), this->movies.end(), m));
	writeToFile();
}

void Repository::updateMovie(Movie & m)
{
	if (find(this->movies.begin(), this->movies.end(), m) == this->movies.end())
		throw RepositoryException("There is no movie with this title in the repository.");
	replace(this->movies.begin(), this->movies.end(), m, m);
	writeToFile();
	
}

Movie Repository::getMovie(const std::string & title)
{
	vector<Movie> movies = getMovies();
	for (Movie m : movies) {
		if (m.getTitle() == title) {
			return m;
		}
	}
	return Movie();
}

void Repository::emptyRepo()
{
	ofstream file(this->filename);
	file.clear();
	file.close();
	movies.clear();

}

vector<Movie> Repository::getMoviesByGenre(const std::string& genre) const
{

	vector<Movie> movies = getMovies();
	vector<Movie> res{};
	for (Movie m : movies) {
		if (m.getGenre() == genre) {
			res.push_back(m);
		}
	}
	if (res.size() == 0) {
		res = movies;
	}
	return res;
}

