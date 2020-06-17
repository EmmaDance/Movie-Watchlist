#include "UI.h"
#include "RepositoryExceptions.h"
#include <algorithm>
using namespace std;

void UI::printMenu()
{
	cout << endl;
	cout << "1 - Admin"<<endl;
	cout << "2 - User" << endl;
	cout << "0 - Exit." << endl;
}

void UI::printAdminMenu()
{
	cout << endl;
	cout << "1 - Add" << endl;
	cout << "2 - Delete" << endl;
	cout << "3 - Update" << endl;
	cout << "4 - See all" << endl;
	cout << "0 - Exit." << endl;
}

void UI::printUserMenu()
{
	cout << endl;
	cout << "1 - See movies." << endl;
	cout << "2 - Delete a movie from the watchlist" << endl;
	cout << "3 - See the watchlist" << endl;
	cout << "4 - Save watchlist to file." << endl;
	cout << "5 - Display watchlist." << endl;
	cout << "0 - Exit." << endl;
}

void UI::seeMovies() {

	cout << "Enter the genre: ";
	std::string genre;
	getline(cin, genre);
	vector<Movie> movies = this->c.getRepo().getMovies();
	//std::vector<Movie> v{ this->c.getRepo().getMoviesByGenre(genre) };

	int n = std::count_if(movies.begin(), movies.end(), [genre](Movie m) {return m.getGenre() == genre; });
	std::vector<Movie> v(n);
	std::copy_if(movies.begin(), movies.end(), v.begin(), [genre](Movie m) {return m.getGenre() == genre; });

	auto it = v.begin();
	Movie m = *it;
	printMovie(m);
	m.play();
	printSubmenu();
	it++;
	int cmd = 0;
	while (true) {
		if (it == v.end())
			it = v.begin();
		cin >> cmd;
		if (cmd == 0) {
			break;
		}
		switch (cmd) {
		case 1:
			this->c.addMovieToWatchlist(m);
			break;
		case 2:
			break;
		}
		m = *it;
		printMovie(m);
		m.play();
		printSubmenu();
		it++;
	}
}

void UI::printMovie(const Movie& m) {
	cout << m.getTitle() << " - " << m.getGenre() << " from " << m.getYear() << " - " << m.getLikes() << " likes." << endl;
}

void UI::printSubmenu() {
	cout << "Press 1 to add the movie to your watchlist." << endl;
	cout << "Press 2 to see the next movie." << endl;
	cout << "Press 0 to go back." << endl;
}

void UI::seeWatchlist()
{
	vector<Movie> movies = this->c.getWatchlist().getMovies();
	if (movies.size() == 0)
	{
		cout << "There are no movies in the watchlist." << endl;
		return;
	}

	for (int i = 0; i < movies.size(); i++)
	{
		Movie m = movies[i];
		cout << m.getTitle() << " - " << m.getGenre() << " from " << m.getYear() << " - " << m.getLikes() << " likes." << endl;
	}
}

void UI::addMovieToRepo()
{
	cout << "Enter the title: ";
	std::string title;
	getline(cin, title);
	cout << "Enter the genre: ";
	std::string genre;
	getline(cin, genre);
	int year = 0;
	cout << "Enter the year: " << endl;
	while (!(cin >> year))
	{
		cin.clear();
	    cin.ignore();
		cout << "Invalid year. Please try again: " << endl;
	}
	cout << "Enter number of likes: " << endl;
	int likes = 0;
	while (!(cin >> likes))
	{
		cin.clear();
		//cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input. Number of likes must be an integer. Please try again: " << endl;
	}
	cin.ignore();
	cout << "Trailer link: ";
	std::string trailer;
	getline(cin, trailer);
	try {
		this->c.addMovieToRepository(title, genre, year, likes, trailer);
	}
	catch(MovieException& e){
		cout << e.getMessage();
	}
	catch (DuplicateMovieException& e) {
		cout << e.what();
	}
}

void UI::deleteMovieFromRepo()
{
	cout << "Enter the title: ";
	std::string title;
	getline(cin, title);
	try {
		this->c.deleteMovieFromRepository(title);
	}
	catch (RepositoryException& e) {
		cout << e.what();
	}
}

Movie UI::deleteMovieFromWatch()
{
	cout << "Enter the title of the movie to delete: ";
	std::string title;
	getline(cin, title);
	this->c.deleteMovieFromWatchlist(title);
	return c.getMovieFromRepository(title);
}

void UI::rateMovie(Movie & m)
{
	cout << "Did you like the movie? Press 1 for yes, 0 for no." << endl;
	int like = 0;
	cin >> like;
	c.updateMovieInRepository(m.getTitle(), m.getGenre(), m.getYear(), m.getLikes() + like, m.getTrailer());
}

void UI::saveWatchlist()
{
	this->c.saveWatchlistToFile();
}

void UI::displayWatchlist()
{
	this->c.openWatchlist();

}

void UI::updateMovieInRepo()
{
	cout << "Enter the title: ";
	std::string title;
	getline(cin, title);
	cout << "Enter the genre: ";
	std::string genre;
	getline(cin, genre);
	int year = 0;
	cout << "Enter the year: " << endl;
	while (!(cin >> year))
	{
		cin.clear();
		//std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid year. Please try again: " << endl;
	}
	cout << "Enter number of likes: " << endl;
	int likes = 0;
	while (!(cin >> likes))
	{
		cin.clear();
		//cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input. Number of likes must be an integer. Please try again: " << endl;
	}
	cin.ignore();
	cout << "Trailer link: ";
	std::string trailer;
	getline(cin, trailer);
	try {
		this->c.updateMovieInRepository(title, genre, year, likes, trailer);
	}
	catch (RepositoryException& e) {
		cout << e.what();
	}
		
}

void UI::displayAllMoviesRepo()
{
	vector<Movie> movies = this->c.getRepo().getMovies();
	if (movies.size() == 0)
	{
		cout << "There are no movies in the repository." << endl;
		return;
	}

	for (int i = 0; i < movies.size(); i++)
	{
		Movie m = movies[i];
		cout << m.getTitle() << " - " << m.getGenre() << " from " << m.getYear() << " - " << m.getLikes() << " likes." << endl;
	}
}

void UI::start()
{
	while (true)
	{
		UI::printMenu();
		int command{ 0 };
		cout << "Enter your command: ";
		cin >> command;
		cin.ignore();
		if (command == 0)
			break;
		if (command == 1)
		{
			while (true)
			{
				UI::printAdminMenu();
				int commandAdmin{0};
				cout << "Enter your command: ";
				cin >> commandAdmin;
				cin.ignore();
				if (commandAdmin == 0)
					break;
				switch (commandAdmin)
				{
				case 1:
					this->addMovieToRepo();
					break;
				case 2:
					deleteMovieFromRepo();
					break;
				case 3:
					updateMovieInRepo();
					break;
				case 4:
					this->displayAllMoviesRepo();
					break;
				case 0:
					break;
				}
			}			
		}

		if (command == 2)
		{
			while (true)
			{
				UI::printUserMenu();
				int commandUser{0};
				cout << "Input the command: ";
				cin >> commandUser;
				cin.ignore();
				if (commandUser == 0)
					break;
				switch (commandUser)
				{
				case 1:
				{	
					seeMovies();
					break;
				}
				case 2:
				{
					seeWatchlist();
					Movie m = deleteMovieFromWatch();
					rateMovie(m);
					break;
				}
				case 3:
				{
					seeWatchlist();
					break;
				}
				case 4:
				{
					saveWatchlist();
					break;
				}
				case 5:
					displayWatchlist();
					break;
				}
			}
		}
	}
}