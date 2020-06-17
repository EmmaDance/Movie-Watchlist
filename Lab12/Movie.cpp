#include "Movie.h"
#include "Utils.h"
#include <Windows.h>
#include <shellapi.h>
#include<iostream>
#include <vector>
#include <string>
using namespace std;


Movie::Movie() : title(""), genre(""), year(0), trailer("") {};

Movie::Movie(const std::string& title, const std::string& genre = "", const int year = 0 , const int likes = 0, const std::string& trailer = "#")
{
	this->title = title;
	this->genre = genre;
	this->year = year;
	this->likes = likes;
	this->trailer = trailer;
}

std::string Movie::toHTML()
{
	return "\t\t<tr>\n\t\t\t<td>" + this->title + "</td>\n\t\t\t<td>" + this->genre + "</td>\n\t\t\t<td>" + to_string(this->year) + "</td>\n\t\t\t<td>" + to_string(this->likes) + "</td>\n\t\t\t<td><a href = \"" + this->trailer + "\">Link</a></td>\n\t\t</tr>";
}

std::string Movie::toStr()
{
	return title + "," + genre + "," + to_string(year) + "," + to_string(likes) + "," + trailer;
}

void Movie::play()
{	ShellExecuteA(NULL, NULL, "chrome.exe", this->getTrailer().c_str(), NULL, SW_SHOWMAXIMIZED);}

std::istream & operator>>(std::istream & is, Movie & m)
{
	string line;
	getline(is, line);
	vector<string> tokens = tokenize(line, ',');
	if (tokens.size() != 5) // make sure all the song data was valid
		return is;
	m.title = tokens[0];
	m.genre = tokens[1];
	m.year = stoi(tokens[2], 0, 10);
	m.likes = stoi(tokens[3],0,10);
	m.trailer = tokens[4];
	return is;
}

std::ostream & operator<<(std::ostream & os, const Movie & m)
{
	os << m.title << "," << m.genre << "," << m.year << "," << m.likes << "," << m.trailer << "\n";
	return os;
}
