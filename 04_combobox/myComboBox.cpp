#include <string>
#include "QDebug"
#include "myComboBox.h"

void myComboBox::setHandleObject(QObject *comboBox, QObject *textView) {
    myComboBox::comboBox = comboBox;
    myComboBox::textView = textView;
}

void myComboBox::handleComboBox(void) {
    if(myComboBox::comboBox != NULL) {
        myComboBox::selectIndex = myComboBox::comboBox->property("currentIndex").toInt();
        std::string temp = "You select ";
        temp += std::to_string(myComboBox::selectIndex);
        char show_text[temp.length()];
        strcpy(show_text, temp.c_str());
        myComboBox::textView->setProperty("text", show_text);
        qDebug() << "Combobox click " << myComboBox::selectIndex;
    }
}

void myComboBox::handleButton(void) {
    qDebug() << "reset click";
    if(myComboBox::comboBox != NULL) {
        myComboBox::comboBox->setProperty("currentIndex", 0);
    }
    myComboBox::selectIndex = 0;
}
