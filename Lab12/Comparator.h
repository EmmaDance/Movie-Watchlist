#pragma once

template<typename T>
class Comparator {
public:
	Comparator() {};
	virtual ~Comparator() {};
	virtual bool compare(T, T) = 0;
};