#include "Tests.h"
#include <vector>
using namespace std;

void Tests::testMovie()
{

	Movie m{ "Hacksaw Ridge", "Drama",2016, 82,"https://www.youtube.com/watch?v=s2-1hz1juBI" };
	assert(m.getGenre() == "Drama");
	assert(m.getTitle() == "Hacksaw Ridge");
	assert(m.getTrailer() == "https://www.youtube.com/watch?v=s2-1hz1juBI");
	assert(m.getLikes() == 82);
	assert(m.getYear() == 2016);
}

void Tests::testWatchlist() {
	WatchList w{};
	Movie m{ "Hacksaw Ridge", "Drama",2016, 82,"https://www.youtube.com/watch?v=s2-1hz1juBI" };
	w.addMovie(m);
	vector<Movie> movies = w.getMovies();
	assert(movies.size() == 1);
	assert(w.isEmpty() == false);
}

void Tests::testRepository()
{
	Repository repo{"tests.txt"};

	Movie m{ "Hacksaw Ridge", "Drama",2016, 82,"https://www.youtube.com/watch?v=s2-1hz1juBI" };
	Movie m9{ "Back to the Future","Comedy",1985,85,"https://www.youtube.com/watch?v=qvsgGtivCgs" };
	Movie m1{ "Hacksaw Ridge", "Drama",2016, 83,"https://www.youtube.com/watch?v=s2-1hz1juBI" };
	
	repo.addMovie(m);
	repo.addMovie(m9);
	vector<Movie> movies = repo.getMovies();
	assert(movies.size() == 2);
	repo.updateMovie(m1);
	assert(repo.getMovie("Hacksaw Ridge").getLikes() == 83);
	repo.deleteMovie(m);
	movies = repo.getMovies();
	assert(movies.size() == 1);
	vector<Movie> movies1 = repo.getMoviesByGenre("Comedy");
	assert(movies1.size() == 1);
	repo.addMovie(m);
	vector<Movie> movies2 = repo.getMoviesByGenre("Action");
	assert(movies2.size() == 2);
	repo.emptyRepo();
}


void Tests::testController()
{
	Repository repo{"tests.txt"};
	FileWatchList* watchlist;
	watchlist = new CSVWatchList{ "watchlistTests.csv" };
	Controller c(repo, watchlist, MovieValidator{});
	c.addMovieToRepository("Hacksaw Ridge", "Drama", 2016, 82, "https://www.youtube.com/watch?v=s2-1hz1juBI");
	c.addMovieToRepository("Loving Leah", "Romance", 2009, 71, "https://www.youtube.com/watch?v=nQ-5CwQhkAs");
	c.deleteMovieFromRepository("Loving Leah");
	assert(c.getRepo().getMovies().size() == 1);
	c.updateMovieInRepository("Hacksaw Ridge", "History", 2016, 82, "https://www.youtube.com/watch?v=s2-1hz1juBI");
	assert(c.getMovieFromRepository("Hacksaw Ridge").getGenre() == (std::string)"History");
	Movie m{ "Hacksaw Ridge", "Drama",2016, 82,"https://www.youtube.com/watch?v=s2-1hz1juBI" };
	Movie m9{ "Back to the Future","Comedy",1985,85,"https://www.youtube.com/watch?v=qvsgGtivCgs" };
	c.addMovieToWatchlist(m);
	c.addMovieToWatchlist(m9);
	assert(c.getWatchlist().getMovies().size() == 2);
	c.deleteMovieFromWatchlist("Back to the Future");
	assert(c.getWatchlist().getMovies().size() == 1);
	delete watchlist;
	repo.emptyRepo();
}

void Tests::testComparator()
{
	Comparator<Movie>* compTitle  = new ComparatorAscendingByTitle;
	Comparator<Movie>* compLikes = new ComparatorDescendingByLikes;
	Movie m1{ "Hacksaw Ridge", "Drama",2016, 82,"https://www.youtube.com/watch?v=s2-1hz1juBI" };
	Movie m2{ "Back to the Future","Comedy",1985,85,"https://www.youtube.com/watch?v=qvsgGtivCgs" };
	assert(compTitle->compare(m1, m2) == false);
	assert(compLikes->compare(m2, m1) == true);
	vector<Movie> da;
	da.push_back(m1);
	da.push_back(m2);
	Movie m3{ "Twelve Years a Slave", "History", 2013, 81, "https://www.youtube.com/watch?v=z02Ie8wKKRg" };
	da.push_back(m3);
	sort(da, compTitle);
	assert(da[0].getTitle() == "Back to the Future");
	sort(da, compLikes);
	assert(da[0].getLikes() == 85);
	delete compTitle;
	delete compLikes;
}

void Tests::testAll()
{
	testMovie();
	testRepository();
	testController();
	testWatchlist();
	testComparator();
}