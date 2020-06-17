#include "Lab12.h"
#include "MyGUI.h"
#include "MovieValidator.h"
#include "FIleWatchList.h"
#include "Repository.h"
#include <QtWidgets/QApplication>
#include <QInputDialog>
#include <QStringList>
#include <string>
#include "WatchListModel.h"
#include "Controller.h"
using namespace std;

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QStringList items;
	items << "HTML" << "CSV";
	bool ok;
	string type;

	QString item =  QInputDialog::getItem((QWidget *)nullptr, "Watchlist type" ,
		"Please choose the type of the watchlist: ", items, 0, false, &ok);

	if (ok && !item.isEmpty())
		type = item.toStdString();

	FileWatchList* watchlist;
	if (type == "HTML") {
		watchlist = new HTMLWatchList{ "watchlist.html" };
	}
	else
		watchlist = new CSVWatchList{ "watchlist.csv" };
	Repository repo{ "movies.txt" };
	Controller c(repo, watchlist, MovieValidator{});
	WatchListModel* model = new WatchListModel{*watchlist};
	MyGUI gui{ c, model };
	gui.show();
	return a.exec();
}