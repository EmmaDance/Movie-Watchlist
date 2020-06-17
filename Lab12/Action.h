#pragma once
#include "Movie.h"
#include "Repository.h"
class Action
{
protected:
	Movie movie;
	Repository & repo;

public:
	Action(Movie m, Repository& repo): movie{ m }, repo{ repo }{}
	virtual ~Action();
	virtual void executeUndo() = 0;
	virtual void executeRedo() = 0;
};


class AddAction :public Action
{
public :
	AddAction(Movie m, Repository& repo): Action{m, repo}{}
	~AddAction();
	void executeUndo();
	void executeRedo();
};

class DeleteAction :public Action
{
public:
	DeleteAction(Movie m, Repository& repo) : Action{ m, repo } {}
	~DeleteAction();
	void executeUndo();
	void executeRedo();
};

class UpdateAction :public Action
{
private:
	Movie oldMovie;
public:
	UpdateAction(Movie om, Movie m, Repository& repo) : Action{ m, repo }, oldMovie{ om } {}
	~UpdateAction();
	void executeUndo();
	void executeRedo();
};