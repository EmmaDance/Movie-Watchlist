#pragma once
#include <string>
#include <iostream>
#include <Windows.h>
#include <shellapi.h>

class Movie
{
private:
	std::string title;
	std::string genre;
	int year;
	int likes;
	std::string trailer;

public:
	// default constructor for a movie
	Movie();

	// constructor with parameters
	Movie(const std::string& title, const std::string& genre, const int year, const int likes, const std::string& trailer);
	
	std::string getTitle() const { return title; }

	std::string getGenre() const { return genre; }
	
	int getYear() const { return year; }
	
	int getLikes() const { return likes; }
	
	std::string getTrailer() const { return trailer; }
	
	void setLikes(int newLikes) { likes = newLikes; }

	bool operator==(const Movie& m) { return this->title == m.title; }

	friend std::istream& operator>>(std::istream& is, Movie& m);
	friend std::ostream& operator<<(std::ostream& os, const Movie& m);

	std::string toHTML();
	std::string toStr();
	
	 //Watches the current movie: the page corresponding to the source trailer is opened in a browser.
	void play();

};

