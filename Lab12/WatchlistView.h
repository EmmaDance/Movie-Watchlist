#pragma once

#include <QWidget>
#include <QListView>
#include "ui_WatchlistView.h"
#include "Repository.h"
#include "WatchListModel.h"

class WatchlistView : public QWidget
{
	Q_OBJECT

public:
	WatchlistView(WatchListModel* model, QWidget *parent = Q_NULLPTR);
	~WatchlistView();

private:
	Ui::WatchlistView ui;
	QListView* listView;
	WatchListModel* model;
};
