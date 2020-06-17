#pragma once
#include "Movie.h"
#include "Comparator.h"


class ComparatorAscendingByTitle :public Comparator<Movie> {
public:
	ComparatorAscendingByTitle() {};
	~ComparatorAscendingByTitle() {};
	bool compare(Movie m1, Movie m2)  {
		return m1.getTitle() < m2.getTitle();
	}
};

class ComparatorDescendingByLikes :public Comparator<Movie> {
public:
	ComparatorDescendingByLikes() {};
	~ComparatorDescendingByLikes () {};
	
	bool compare(Movie m1, Movie m2)  {
		return m1.getLikes() > m2.getLikes();
	}
};