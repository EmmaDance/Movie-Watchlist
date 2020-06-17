#include "WatchlistView.h"
#include "WatchListModel.h"

WatchlistView::WatchlistView(WatchListModel* model,QWidget *parent)
	: QWidget(parent), model{model}
{
	ui.setupUi(this);
	this->ui.listView->setModel(model);
}

WatchlistView::~WatchlistView()
{

}

