#include <string>
#include "QDebug"
#include "myButton.h"

using namespace std;

void myButton::buttonClick(void) {
    myButton::counter++;
    qDebug() << "counter: " << counter;
    myButton::setText();
}

void myButton::resetClick(void) {
    qDebug() << "Reset counter";
    myButton::counter = 0;
    myButton::setText();
}
void myButton::setQObectText(QObject *obj) {
    myButton::text = obj;
}
void myButton::setText(void) {
    if(myButton::text != NULL) {
        string temp = "counter ";
        temp += to_string(myButton::counter);
        char show_text[temp.length()];
        strcpy(show_text, temp.c_str());
        myButton::text->setProperty("text", show_text);
    }
    qDebug() << myButton::text;
}
