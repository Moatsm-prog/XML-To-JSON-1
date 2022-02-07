QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Sources/main.cpp \
    Sources/xml_editor.cpp \
    Sources/graph.cpp

HEADERS += \
    Headers/compression.h \
    Headers/files_and_check.h \
    Headers/format.h \
    Headers/header.h \
    Headers/json.h \
    Headers/tree.h \
    Headers/xml_editor.h \
    Headers/graph.h

FORMS += \
    Forms/xml_editor.ui \
    Forms/graph.ui

RC_ICONS = Resourses/icon.ico

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resourses/Resourses.qrc
