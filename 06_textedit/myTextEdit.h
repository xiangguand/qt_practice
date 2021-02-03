#ifndef MYTEXTEDIT_H
#define MYTEXTEDIT_H

#include <String>
#include "QObject"
#include "QDebug"

using namespace std;

class myTextEdit : public QObject {
public:
    myTextEdit(void);
    ~myTextEdit(void);

Q_OBJECT
public slots:
    void handleTextEdit(QString changeText);
    void handleTextField(QString changeText);
    void handleTextInput(QString changeText);
};


#endif /* MYTEXTEDIT_H */
