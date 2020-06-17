#include "User.h"
#include <vector>
#include "Movie.h"
#include <QMessageBox>
#include "RepositoryExceptions.h"

using namespace std;

User::User(Controller& c, QWidget *parent)
	: QWidget(parent), c{c}
{
	ui.setupUi(this);
	this->movies = this->c.getRepo().getMovies();
	this->iterator = this->movies.end();
	QObject::connect(this->ui.startButton, &QPushButton::clicked, this, &User::startButtonHandler);
	QObject::connect(this->ui.nextButton, &QPushButton::clicked, this, &User::nextButtonHandler);
	QObject::connect(this->ui.addButton, &QPushButton::clicked, this, &User::addButtonHandler);
	QObject::connect(this->ui.deleteButton, &QPushButton::clicked, this, &User::deleteButtonHandler);
	QObject::connect(this->ui.saveButton, &QPushButton::clicked, this, &User::saveButtonHandler);
	QObject::connect(this->ui.seeButton, &QPushButton::clicked, this, &User::seeButtonHandler);
}

User::~User()
{
}

void User::startButtonHandler()
{
	this->ui.currentMovie->clear();
	QString genre = this->ui.genreEdit->text();
	if (genre.length()<2) {
		QMessageBox msg{ QMessageBox::Critical, "Error", "You have to input the genre!", QMessageBox::NoButton };
		msg.exec();
	}
	else {
		this->movies = this->c.getMoviesByGenre(genre.toStdString());
		this->iterator = this->movies.begin();
		Movie m = *iterator;
		this->ui.currentMovie->addItem(QString::fromStdString(m.toStr()));
		m.play();
	}
}

void User::nextButtonHandler()
{
	if (this->iterator == this->movies.end()) {
		QMessageBox msg{ QMessageBox::Critical, "Error","You need to start first!" };
		msg.exec();
	}
	else {
		this->ui.currentMovie->clear();
		this->iterator++;
		if (this->iterator == this->movies.end())
			this->iterator = this->movies.begin();
		Movie m = *iterator;
		this->ui.currentMovie->addItem(QString::fromStdString(m.toStr()));
		m.play();
	}
}

void User::addButtonHandler()
{

	if (this->iterator == this->movies.end()) {
		QMessageBox msg{ QMessageBox::Critical, "Error","You need to start first!" };
		msg.exec();
	}
	else
	{
		try {
			this->c.addMovieToWatchlist(*this->iterator);
		}
		catch (RepositoryException& e)
		{
			QMessageBox msg{ QMessageBox::Critical, "Error",e.what()};
			msg.exec();
		}
	}

}


void User::deleteButtonHandler()
{
	if (this->iterator == this->movies.end()) {
		QMessageBox msg{ QMessageBox::Critical, "Error","You need to start first!" };
		msg.exec();
	}
	else {
		Movie m = *this->iterator;
		this->c.deleteMovieFromWatchlist(m.getTitle());
		QMessageBox msg{ QMessageBox::Information, "Rating", "Did you like the movie?",QMessageBox::Yes | QMessageBox::No };
		msg.exec();
		int like = 0;
		if (msg.buttonRole(msg.clickedButton()) == QMessageBox::YesRole) {
			like = 1;
		}
		this->c.updateMovieInRepository(m.getTitle(), m.getGenre(), m.getYear(), m.getLikes() + like, m.getTrailer());
	}
}

void User::saveButtonHandler()
{
	this->c.saveWatchlistToFile();
}

void User::seeButtonHandler()
{
	this->c.openWatchlist();
}

