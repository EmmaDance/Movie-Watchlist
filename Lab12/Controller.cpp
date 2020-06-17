#include "Controller.h"
#include <string>
#include <algorithm>
#include "Action.h"

using namespace std;

void Controller::addMovieToRepository(const std::string& title, const std::string& genre, int year, int likes,const std::string& trailer)
{
	Movie m{ title, genre,year,likes,trailer };
	MovieValidator::validate(m);
	this->repo.addMovie(m);
	Action* a = new AddAction{ m,this->repo };
	this->stack.push(a);
}

void Controller::deleteMovieFromRepository(const std::string & title)
{
	Movie m = this->repo.getMovie(title);
	this->repo.deleteMovie(m);
	Action* a = new DeleteAction{ m,this->repo };
	this->stack.push(a);
}

void Controller::updateMovieInRepository(const std::string & title, const std::string & genre, int year, int likes, const std::string & trailer)
{
	Movie m{ title,genre,year,likes,trailer };
	Movie om = getMovieFromRepository(title);
	this->repo.updateMovie(m);
	Action* a = new UpdateAction{om, m,this->repo };
	this->stack.push(a);
}

Movie Controller::getMovieFromRepository(const std::string & title)
{
	return this->repo.getMovie(title);
}

void Controller::addMovieToWatchlist(const Movie& m)
{
	this->watchlist->addMovie(m);
}

void Controller::deleteMovieFromWatchlist(const std::string & title)
{
	Movie m = this->watchlist->getMovie(title);
	this->watchlist->deleteMovie(m);
}

void Controller::saveWatchlistToFile()
{
	if (this->watchlist == nullptr)
		return;

	this->watchlist->writeToFile();
}

void Controller::openWatchlist()
{
	if (this->watchlist == nullptr)
		return;

	this->watchlist->display();
}

std::vector<Movie> Controller::getMoviesByGenre(const std::string & genre)
{
	vector<Movie> movies = getRepo().getMovies();
	int n = std::count_if(movies.begin(), movies.end(), [genre](Movie m) {return m.getGenre() == genre; });
	std::vector<Movie> v(n);
	std::copy_if(movies.begin(), movies.end(), v.begin(), [genre](Movie m) {return m.getGenre() == genre; });
	if (v.size() == 0)
		v = movies;
	return v;
}

void Controller::undo()
{
	if (this->stack.isEmpty())
		throw exception{ "Can't undo!" };
	Action* a = this->stack.pop();
	a->executeUndo();
	this->stack.decrement();

}

void Controller::redo()
{
	this->stack.increment();
	Action* a = this->stack.pop();
	a->executeRedo();
}

void sort(vector<Movie>& v, Comparator<Movie>* c) {
	bool done = false;
	while(!done){
		done = true;
		for (int i = 0; i < v.size() - 1; i++) {
			if (!c->compare(v[i], v[i + 1])) {
				Movie aux;
				aux = v[i];
				v[i] = v[i + 1];
				v[i + 1] = aux;
				done = false;
			}
		}
	}
}
