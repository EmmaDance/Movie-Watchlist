#include "ActionStack.h"
#include <exception>

using namespace std;

ActionStack::ActionStack()
{
	current = -1;
}


ActionStack::~ActionStack()
{
}

void ActionStack::push(Action* a)
{
	this->elems.push_back(a);
	this->current++;
	this->size = this->current+1;
}

Action* ActionStack::pop()
{
	if (current == -1) {
		throw exception{ "Can't undo anymore!" };
		this->current--;
	}
	return this->elems[current];

}

void ActionStack::increment()
{ 
	this->current++;  
	if (this->current >= this->size) {
		this->current--;
		throw exception{ "Can't redo anymore!" };
	}
}
