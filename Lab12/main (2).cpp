#include "UI.h"
#include "Tests.h"
#include "FIleWatchList.h"
#include "RepositoryExceptions.h"
#include <Windows.h>
#include <crtdbg.h>
using namespace std;
int main2()
{
	//Tests::testAll();

	try
	{
		Repository repo("movies.txt");
		FileWatchList* watchlist = nullptr;
		cout << "What type of file would you like to use to store the watchlist (CSV/HTML)?";
		string type{};
		cin >> type;
		if (type == "HTML")
			watchlist = new HTMLWatchList{ "watchlist.html" };
		else
			watchlist = new CSVWatchList{ "watchlist.csv" };
		Controller c(repo, watchlist, MovieValidator{});
		UI ui(c);
		ui.start();
		delete watchlist;
	}
	catch (FileException&)
	{
		cout << "Repository file could not be opened! The application will terminate." << endl;
		return 1;
	}

	return 0;
}

int main() {
	main2();
	_CrtDumpMemoryLeaks();
}


//Movie m1{ "Hacksaw Ridge", "Drama",2016, 82,"https://www.youtube.com/watch?v=s2-1hz1juBI" };
//Movie m2{ "Loving Leah", "Romance",2009,71, "https://www.youtube.com/watch?v=nQ-5CwQhkAs" };
//Movie m3{ "Twelve Years a Slave", "History", 2013, 81, "https://www.youtube.com/watch?v=z02Ie8wKKRg" };
//Movie m4{"Pay It Forward","Drama",2000,72,"https://www.youtube.com/watch?v=qfW0wCV9iFI"};
//Movie m5{"Coach Carter","Biography",2005,73,"https://www.youtube.com/watch?v=znyAnWUYf2g" };
//Movie m6{"A Shine of Rainbows","Drama",2009,72,"https://www.youtube.com/watch?v=BYdEm9IdwDo"};
//Movie m7{"Les Miserables","Musical",2012,76,"https://www.youtube.com/watch?v=IuEFm84s4oI" };
//Movie m8{"Ip Man","Action",2008,80,"https://www.youtube.com/watch?v=1AJxXQ7xojE"};
//Movie m9{"Back to the Future","Comedy",1985,85,"https://www.youtube.com/watch?v=qvsgGtivCgs"};
//Movie m10{"Holes","Comedy",2003,71,"https://www.youtube.com/watch?v=6yN1RY3c0TA"};

//repo.addMovie(m1);
//repo.addMovie(m2);
//repo.addMovie(m3);
//repo.addMovie(m4);
//repo.addMovie(m5);
//repo.addMovie(m6);
//repo.addMovie(m7);
//repo.addMovie(m8);
//repo.addMovie(m9);
//repo.addMovie(m10);