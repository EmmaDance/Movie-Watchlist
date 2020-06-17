#include "Admin.h"
#include "Controller.h"
#include <QString>
#include <vector>
#include "Movie.h"
#include <QMessageBox>
#include "RepositoryExceptions.h"

using namespace std;

Admin::Admin(Controller& c, QWidget *parent)
	: QWidget(parent), c{c}
{
	ui.setupUi(this);
	populateList();
	QObject::connect(this->ui.addButton, &QPushButton::clicked, this, &Admin::addButtonHandler);
	QObject::connect(this->ui.removeButton, &QPushButton::clicked, this, &Admin::removeButtonHandler);
	QObject::connect(this->ui.updateButton, &QPushButton::clicked, this, &Admin::updateButtonHandler);
	QObject::connect(this->ui.listWidget, &QListWidget::itemSelectionChanged, this, [this]() {this->listSelectedItem(); });
	QObject::connect(this->ui.comboBox, &QComboBox::currentTextChanged,this,&Admin::populateList);
	QObject::connect(this->ui.undoButton, &QPushButton::clicked, this, &Admin::undo);
	QObject::connect(this->ui.redoButton, &QPushButton::clicked, this, &Admin::redo);
}

Admin::~Admin()
{
}

void Admin::populateList()
{
	int idx = this->ui.comboBox->currentIndex();
	this->ui.listWidget->clear();
	vector<Movie> movies = this->c.getRepo().getMovies();
	for (Movie m : movies) {
		if(idx == 0)
		 this->ui.listWidget->addItem(QString::fromStdString(m.getTitle()));
		else
			this->ui.listWidget->addItem(QString::fromStdString(m.toStr()));
	}
}

void Admin::addButtonHandler()
{
	QString title = this->ui.titleEdit->text();
	QString genre = this->ui.genreEdit->text();
	QString year = this->ui.yearEdit->text();
	QString likes = this->ui.likesEdit->text();
	QString trailer = this->ui.trailerEdit->text();
	if (title.length() < 2 || genre.length() < 2 || year.length() < 2 || likes.length() < 2 || trailer.length() < 2)
	{
		QMessageBox msg{ QMessageBox::Critical, "Error", "You need to fill out all the fields!" };
		msg.exec();
		return;
	}
	try {
		this->c.addMovieToRepository(title.toStdString(), genre.toStdString(), year.toInt(), likes.toInt(), trailer.toStdString());
		populateList();
	}
	catch (RepositoryException& e) {
		QMessageBox msg{ QMessageBox::Critical, "Error", e.what() };
		msg.exec();
	}
}

void Admin::removeButtonHandler()
{
	QString title = this->ui.titleEdit->text();
	try {
		this->c.deleteMovieFromRepository(title.toStdString());
		populateList();
	}
	catch (RepositoryException& e) {
		QMessageBox msg(QMessageBox::Critical, "Error", QString::fromStdString(e.what()));
		msg.exec();
	}
}

void Admin::updateButtonHandler()
{
	QString title = this->ui.titleEdit->text();
	QString genre = this->ui.genreEdit->text();
	QString year = this->ui.yearEdit->text();
	QString likes = this->ui.likesEdit->text();
	QString trailer = this->ui.trailerEdit->text();
	try {
		this->c.updateMovieInRepository(title.toStdString(), genre.toStdString(), year.toInt(), likes.toInt(), trailer.toStdString());
		populateList();
	}
	catch (RepositoryException& e)
	{
		QMessageBox msg{ QMessageBox::Critical, "Error", e.what() };
	}
}

void Admin::undo()
{
	try {
		this->c.undo();
		populateList();
	}
	catch (exception& e)
	{
		QMessageBox msg{ QMessageBox::Critical, "Undo", e.what() };
		msg.exec();
	}
}

void Admin::redo()
{
	try {
		this->c.redo();
		populateList();
	}
	catch (exception& e)
	{
		QMessageBox msg{ QMessageBox::Critical, "Undo", e.what() };
		msg.exec();
	}
}

void Admin::listSelectedItem()
{
	int idx = this->getSelectedIndex();
	if (idx == -1)
		return;

	// get the movie at the selected index
	if (idx >= this->c.getRepo().getMovies().size())
		return;

	Movie m = this->c.getRepo().getMovies()[idx];

	this->ui.titleEdit->setText(QString::fromStdString(m.getTitle()));
	this->ui.genreEdit->setText(QString::fromStdString(m.getGenre()));
	this->ui.yearEdit->setText(QString::fromStdString(to_string(m.getYear())));
	this->ui.likesEdit->setText(QString::fromStdString(to_string(m.getLikes())));
	this->ui.trailerEdit->setText(QString::fromStdString(m.getTrailer()));
}

int Admin::getSelectedIndex()
{
	if (this->ui.listWidget->count() == 0)
		return -1;

	// get selected index
	QModelIndexList index = this->ui.listWidget->selectionModel()->selectedIndexes();
	if (index.size() == 0)
	{
		this->ui.titleEdit->clear();
		this->ui.genreEdit->clear();
		this->ui.yearEdit->clear();
		this->ui.likesEdit->clear();
		this->ui.trailerEdit->clear();
		return -1;
	}

	int idx = index.at(0).row();
	return idx;
}