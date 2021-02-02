#ifndef MYCOMBOBOX_H
#define MYCOMBOBOX_H

#include "QObject"
#include "QDebug"

class myComboBox : public QObject {
public:
    QObject *comboBox;
    QObject *textView;
    void setHandleObject(QObject *comboBox, QObject *textView);
private:
    int selectIndex = 0;
Q_OBJECT
public slots:
    void handleComboBox(void);
    void handleButton(void);
};


#endif /* MYCOMBOBOX_H */
