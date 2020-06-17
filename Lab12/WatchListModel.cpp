#include "WatchListModel.h"



WatchListModel::~WatchListModel()
{
}

int WatchListModel::rowCount(const QModelIndex & parent) const
{
	int moviesCount = this->watchlist.getMovies().size();
	return moviesCount;
}

QVariant WatchListModel::data(const QModelIndex & index, int role) const
{
	if (role == Qt::DisplayRole) {
		int idx = index.row();
		Movie m = this->watchlist.getMovies()[idx];
		return QString::fromStdString(m.toStr());
	}
	return QVariant();
}