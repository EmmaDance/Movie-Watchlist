#pragma once

#include <string>
#include "WatchList.h"

class FileWatchList : public WatchList {
protected:
	std::string filename;
public:
	virtual void writeToFile() = 0;
	virtual void display() = 0;
};

class CSVWatchList : public FileWatchList {

public:
	CSVWatchList(std::string filename) { this->filename = filename; }
	void writeToFile();
	void display();

};

class HTMLWatchList : public FileWatchList {

public:
	HTMLWatchList(std::string filename) { this->filename = filename; }
	void writeToFile();
	void display();
};