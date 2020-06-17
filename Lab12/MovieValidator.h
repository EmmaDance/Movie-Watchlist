#pragma once
#include <string>
#include "Movie.h"

class MovieException {
private:
	std::string message;
public:
	MovieException(std::string message) { this->message = message; }
	std::string getMessage() { return message; }
};

class MovieValidator {
public:
	static void validate(const Movie& movie);
};
