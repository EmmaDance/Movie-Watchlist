#pragma once

#include <QWidget>
#include <QListWidget>
#include "ui_MyGUI.h"
#include "Admin.h"
#include "User.h"
#include "WatchListModel.h"

class MyGUI : public QWidget
{
	Q_OBJECT

public:
	MyGUI(Controller& c, WatchListModel* model,  QWidget *parent = Q_NULLPTR);
	~MyGUI();
	void adminWidget();
	void userWidget();
	void watchlistView();
private:
	Ui::MyGUI ui;
	Controller& c;
	//QListModel* model;
	QPushButton* adminButton;
	QPushButton* userButton;
	QPushButton* watchlistButton;
	WatchListModel* model;

};