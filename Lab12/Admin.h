#pragma once

#include <QWidget>
#include "ui_Admin.h"
#include "Controller.h"
#include <QComboBox>

class Admin : public QWidget
{
	Q_OBJECT

public:
	Admin(Controller& c, QWidget *parent = Q_NULLPTR);
	~Admin();
	void populateList();
	int getSelectedIndex();

	public slots:

	void addButtonHandler();
	void removeButtonHandler();
	void updateButtonHandler();
	void listSelectedItem();
	void undo();
	void redo();

private:
	Ui::Admin ui;
	Controller& c;
	QComboBox* comboBox;
	QListWidget* list;
	QLineEdit* titleEdit;
	QLineEdit* genreEdit;
	QLineEdit* yearEdit;
	QLineEdit* likesEdit;
	QLineEdit* trailerEdit;
	QPushButton* addButton;
	QPushButton* removeButton;
	QPushButton* updateButton;
	QPushButton* undoButton;
	QPushButton* redoButton;
};
