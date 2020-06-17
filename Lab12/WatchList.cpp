#include "WatchList.h"
#include <exception>
#include "RepositoryExceptions.h"
using namespace std;

WatchList::WatchList()
{
	this->current = 0;
}

void WatchList::addMovie(const Movie& m)
{
	if (find(this->movies.begin(), this->movies.end(), m) == this->movies.end()) {
		this->movies.push_back(m);
		return;
	}
	else
		throw DuplicateMovieException();
}


void WatchList::deleteMovie(Movie & m)
{
	if (this->exists(m))
		this->movies.erase(find(this->movies.begin(), this->movies.end(), m));
}


Movie WatchList::getMovie(const std::string & title)
{
	std::vector<Movie> movies = getMovies();
	for (int i = 0; i < movies.size(); i++) {
		if (movies[i].getTitle() == title) {
			return movies[i];
		}
	}
	return Movie();
}



//Movie WatchList::getCurrentMovie()
//{
//	if (this->current == this->movies.size())
//		this->current = 0;
//	return this->movies[this->current];
//}
//
//void WatchList::play()
//{
//	if (this->movies.size() == 0)
//		return;
//	this->current = 0;
//	Movie currentmovie = this->getCurrentMovie();
//	currentmovie.play();
//}
//
//void WatchList::next()
//{
//	if (this->movies.size() == 0)
//		return;
//	this->current++;
//	Movie currentmovie = this->getCurrentMovie();
//	currentmovie.play();
//}

bool WatchList::isEmpty()
{
	return this->movies.size() == 0;
}

bool WatchList::exists(Movie & m)
{
	if (find(this->movies.begin(), this->movies.end(), m) == this->movies.end())
		return false;
	return true;
}
