#ifndef MYTABLEVIEW_H
#define MYTABLEVIEW_H

#include "QObject"
#include "QDebug"

class myTableView : public QObject {
public:
    myTableView(void);
    ~myTableView(void);
    QObject *tableview;

Q_OBJECT
public slots:
    void handleTableView(int row);
};


#endif /* MYTABLEVIEW_H */
