#include <String>
#include "QDebug"
#include "myTextEdit.h"

using namespace std;

myTextEdit::myTextEdit(void) {
    qDebug() << "Construct TextEdit";
}

myTextEdit::~myTextEdit(void) {
    qDebug() << "Deconstruct TextEdit";
}

void myTextEdit::handleTextEdit(QString changeText) {
    qDebug() << "TextEdit: " << changeText;
}

void myTextEdit::handleTextField(QString changeText) {
    qDebug() << "TextFielde: " << changeText;
}

void myTextEdit::handleTextInput(QString changeText) {
    qDebug() << "TextInput: " << changeText;
}

