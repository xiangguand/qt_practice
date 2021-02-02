#include <string>
#include "QDebug"
#include "myTableView.h"

myTableView::myTableView(void) {
    qDebug() << "Construct TableView";
}

myTableView::~myTableView(void) {
    qDebug() << "Deconstruct TableView";
}

void myTableView::handleTableView(int row) {
    qDebug() << "TableView clicked " << row;
}
