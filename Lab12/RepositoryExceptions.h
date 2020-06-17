#pragma once
#include <exception>
#include <string>

class FileException : public std::exception {
protected:
	std::string message;
public:
	FileException(std::string message) { this->message = message; }
	virtual const char* what(){ return message.c_str(); }
};

class RepositoryException : public std::exception {
protected:
	std::string message;
public:
	RepositoryException() : exception{}, message{ "" } {}
	RepositoryException(const std::string& message) : message{ message } {}
	virtual ~RepositoryException() {}
	virtual const char* what() { return this->message.c_str(); }

};

class DuplicateMovieException : public RepositoryException
{
public:
	 const char* what() override  { return "This movie was already added!"; }
};