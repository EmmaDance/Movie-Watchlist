#include "MyGUI.h"
#include "WatchlistView.h"
#include "WatchListModel.h"

MyGUI::MyGUI(Controller& c, WatchListModel* model, QWidget *parent)
	: QWidget(parent), c{c}, model{model}
{
	ui.setupUi(this);
	QObject::connect(ui.userButton, &QPushButton::clicked, this, &MyGUI::userWidget);
	QObject::connect(ui.adminButton, &QPushButton::clicked, this, &MyGUI::adminWidget);
	QObject::connect(ui.watchlistButton, &QPushButton::clicked, this, &MyGUI::watchlistView);
}

MyGUI::~MyGUI()
{
}

void MyGUI::adminWidget()
{
	Admin* a = new Admin{ this->c };
	a->show();
}

void MyGUI::userWidget()
{
	User* u = new User{this->c };
	u->show();
}

void MyGUI::watchlistView()
{
	WatchlistView* w = new WatchlistView{ this->model};
	w->show();
}
