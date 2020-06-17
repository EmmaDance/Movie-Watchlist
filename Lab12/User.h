#pragma once

#include <QWidget>
#include "ui_User.h"
#include <QPushButton>
#include <QLineEdit>
#include "Controller.h"
#include <iterator>

class User : public QWidget
{
	Q_OBJECT

public:
	User(Controller& c, QWidget *parent = Q_NULLPTR);
	~User();

	public slots:
	void startButtonHandler();
	void nextButtonHandler();
	void addButtonHandler();
	void deleteButtonHandler();
	void saveButtonHandler();
	void seeButtonHandler();

private:
	Ui::User ui;
	Controller& c;
	std::vector<Movie>::iterator iterator;
	std::vector<Movie> movies;
	QLineEdit* genreEdit;
	QListWidget* currentMovie;
	QPushButton* startButton;
	QPushButton* nextButton;
	QPushButton* addButton;
	QPushButton* deleteButton;
	QPushButton* saveButton;
	QPushButton* seeButton;
};
