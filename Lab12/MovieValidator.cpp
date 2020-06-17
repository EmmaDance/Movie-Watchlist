#include "MovieValidator.h"

void MovieValidator::validate(const Movie & movie)
{
	if (movie.getTitle().length() < 2)
		throw MovieException("The title must be at least two characters long.");
	if (movie.getGenre().length() < 2)
		throw MovieException("The genre must be at least two characters long.");
	if (movie.getYear() < 1900)
		throw MovieException("The year must be greater than 1900.");
	if (movie.getLikes() < 0)
		throw MovieException("The number of likes cannot be negative");
}
