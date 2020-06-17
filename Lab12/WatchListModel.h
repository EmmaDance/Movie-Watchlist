#pragma once
#include <QAbstractListModel>
#include "FIleWatchList.h"

class WatchListModel: public QAbstractListModel

{
private:
	FileWatchList & watchlist;
public:
	WatchListModel(FileWatchList& w) :watchlist{ w }{}
	~WatchListModel();
	int rowCount(const QModelIndex &parent = QModelIndex()) const;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
};