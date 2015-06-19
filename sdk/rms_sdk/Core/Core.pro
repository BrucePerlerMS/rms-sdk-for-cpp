REPO_ROOT = $$PWD/../../..
DESTDIR   = $$REPO_ROOT/bin/rms
TARGET    = modcore

TEMPLATE = lib
CONFIG  += staticlib warn_on c++11 debug_and_release
QT      += core
QT      -= gui

CONFIG(debug, debug|release) {
    TARGET = $$join(TARGET,,,d)
}
INCLUDEPATH += $$REPO_ROOT/sdk/rmscrypto_sdk/CryptoStreams/CryptoAPI

SOURCES += ProtectionPolicy.cpp

HEADERS += ProtectionPolicy.h
