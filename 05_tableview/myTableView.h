#ifndef MYBABLEVIEW_H
#define MYBABLEVIEW_H

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


#endif /* MYBABLEVIEW_H */
