#-------------------------------------------------
#
# Project created by QtCreator 2016-09-29T14:51:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = physique
TEMPLATE = app


SOURCES +=\
    main.cpp \
    qsfmlcanvas.cpp \
    widget.cpp \
    4eme-3eme/quatriemetroisieme.cpp \
    4eme-3eme/source/syntheseeudioanimation.cpp \
    4eme-3eme/source/equation_bilan.cpp \
    4eme-3eme/source/fenprinc.cpp \
    4eme-3eme/source/partage_electron.cpp \
    4eme-3eme/source/physik.cpp \
    4eme-3eme/source/ps_element.cpp \
    4eme-3eme/source/syntheseeudio.cpp \
    2nde-1ere/secondepremiere.cpp \
    2nde-1ere/source/physique2nde1ere.cpp \
    2nde-1ere/source/chimie2nde1ere.cpp \
    Forum/forum.cpp \
    2nde-1ere/source/tableauperiodique.cpp \
    2nde-1ere/source/atomedrawer.cpp \
    aboutus.cpp \
    2nde-1ere/source/atome.cpp \
    2nde-1ere/source/circuitelectrique.cpp \
    2nde-1ere/source/circuitsetter.cpp \
    2nde-1ere/source/convertisseur.cpp

HEADERS  += \
    qsfmlcanvas.h \
    widget.h \
    4eme-3eme/quatriemetroisieme.h \
    4eme-3eme/header/syntheseeudioanimation.h \
    4eme-3eme/header/equation_bilan.h \
    4eme-3eme/header/fenprinc.h \
    4eme-3eme/header/partage_electron.h \
    4eme-3eme/header/physik.h \
    4eme-3eme/header/ps_element.h \
    4eme-3eme/header/syntheseeudio.h \
    2nde-1ere/secondepremiere.h \
    2nde-1ere/header/physique2nde1ere.h \
    2nde-1ere/header/chimie2nde1ere.h \
    Forum/forum.h \
    2nde-1ere/header/tableauperiodique.h \
    2nde-1ere/header/atomedrawer.h \
    aboutus.h \
    2nde-1ere/header/atome.h \
    2nde-1ere/header/circuitelectrique.h \
    2nde-1ere/header/circuitsetter.h \
    2nde-1ere/header/convertisseur.h

FORMS    += widget.ui









win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../QtSfml/Release/lib/ -lsfml-main -lsfml-window -lsfml-graphics -lsfml-system
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../QtSfml/Debug/lib/ -lsfml-main-d -lsfml-window-d -lsfml-graphics-d -lsfml-system-d
else:unix: LIBS += -L$$PWD/../../../QtSfml/Debug/lib/ -lsfml-main -lsfml-window -lsfml-graphics -lsfml-system

INCLUDEPATH += $$PWD/../../../QtSfml/include
DEPENDPATH += $$PWD/../../../QtSfml/include
