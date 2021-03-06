REPO_ROOT = $$PWD/../../../..
DESTDIR   = $$REPO_ROOT/bin/rms/platform
TARGET    = platformsettings

TEMPLATE = lib

DEFINES += QTFRAMEWORK

CONFIG += staticlib warn_on c++11 debug_and_release

QT += core network
QT -= gui

CONFIG(debug, debug|release) {
    TARGET = $$join(TARGET,,,d)
}

SOURCES += \
    LanguageSettings.cpp \
    LocalSettingsQt.cpp

HEADERS += \
    ILocalSettings.h \
    ILanguageSettings.h \
    LanguageSettings.h \
    LocalSettingsQt.h

