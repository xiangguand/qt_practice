#!/bin/sh
PATH=/C/Users/zxpay/Desktop/qt5/qt5-build/qtbase/bin:$PATH
export PATH
QT_PLUGIN_PATH=/C/Users/zxpay/Desktop/qt5/qt5-build/qtbase/plugins${QT_PLUGIN_PATH:+:$QT_PLUGIN_PATH}
export QT_PLUGIN_PATH
exec 'C:\Users\zxpay\Desktop\qt5\qt5-build\qtbase\bin\uic.exe' "$@"
