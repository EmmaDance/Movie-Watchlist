#include "FIleWatchList.h"
#include <fstream>
using namespace std;

void CSVWatchList::writeToFile()
{
	ofstream f(this->filename);
	for (auto movie : this->movies) {
		f << movie;
	}
	f.close();
}

void CSVWatchList::display()
{
	ShellExecuteA(NULL, NULL, "notepad.exe", this->filename.c_str(), NULL, SW_SHOWMAXIMIZED);
}


void HTMLWatchList::writeToFile()
{
	ofstream f(this->filename);
	f << "<!DOCTYPE html>\n<html>\n\t<head>\n\t\t<title>Watchlist</title>\n\t\t</head>\n\t\t<body>\n\t\t\t<table border=\"1\">\n\t\t\t<tr>\n";
	f << "\t\t\t<td>Title</td>\n";
	f << "\t\t\t<td>Genre</td>\n";
	f << "\t\t\t<td>Year</td>\n";
	f << "\t\t\t<td>Likes</td>\n";
	f << "\t\t\t<td>Trailer</td>\n";
	f << "\t\t</tr>\n";
	for (auto movie : this->movies) {
		f << movie.toHTML();
	}
	f << "\t\t</table>\n\t</body>\n</html>";
	f.close();
}

void HTMLWatchList::display()
{
	ShellExecuteA(NULL, NULL, "chrome.exe", this->filename.c_str(), NULL, SW_SHOWMAXIMIZED);
}
