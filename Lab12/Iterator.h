#pragma once
#include <vector>

template <typename T>
class IteratorVector {

private:
	std::vector<T> v;
	int current;
	int length;
public:

	IteratorVector(std::vector<T> v) { current = 0; this->v = v; length = v.size(); };
	
	T begin() { return v[0]; };
	
	T end() { return v[length]; }
	
	bool valid() { return current < length; };

	void next() {
		if (valid())
			current++;
		if (!valid())
			current = 0;
	}
	
	T getCurrent() { return v[current]; };
};
