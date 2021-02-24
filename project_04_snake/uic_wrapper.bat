@echo off
SetLocal EnableDelayedExpansion
(set PATH=C:\Users\zxpay\Desktop\qt5\qt5-build\qtbase\bin;!PATH!)
if defined QT_PLUGIN_PATH (
    set QT_PLUGIN_PATH=C:\Users\zxpay\Desktop\qt5\qt5-build\qtbase\plugins;!QT_PLUGIN_PATH!
) else (
    set QT_PLUGIN_PATH=C:\Users\zxpay\Desktop\qt5\qt5-build\qtbase\plugins
)
C:\Users\zxpay\Desktop\qt5\qt5-build\qtbase\bin\uic.exe %*
EndLocal
