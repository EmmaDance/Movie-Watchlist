#pragma once
#include <vector>
#include "Action.h"
class ActionStack
{
	std::vector<Action*> elems;
	int current;
	int size;
public:
	ActionStack();
	~ActionStack();
	void push(Action* a);
	Action* pop();
	bool isEmpty() { return elems.size() == 0; }
	void decrement() { this->current--; }
	void increment();
};

