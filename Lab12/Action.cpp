#include "Action.h"


Action::~Action()
{
}

AddAction::~AddAction()
{
}

void AddAction::executeUndo()
{
	repo.deleteMovie(movie);
}

void AddAction::executeRedo()
{
	repo.addMovie(movie);

}

DeleteAction::~DeleteAction()
{
}

void DeleteAction::executeUndo()
{
	repo.addMovie(movie);

}

void DeleteAction::executeRedo()
{
	repo.deleteMovie(movie);
}

UpdateAction::~UpdateAction()
{
}

void UpdateAction::executeUndo()
{
	repo.updateMovie(oldMovie);
}

void UpdateAction::executeRedo()
{
	repo.updateMovie(movie);
}
