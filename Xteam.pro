QT       += core gui multimedia multimediawidgets
QT        +=sql
QT += printsupport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    animation.cpp \
    chambre.cpp \
    connexion.cpp \
    demande.cpp \
    equipement.cpp \
    evenement.cpp \
    hebergement.cpp \
    historique.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    mainwindowvideo.cpp \
    materiaux.cpp \
    notification.cpp \
    pdf.cpp \
    personnel.cpp \
    qcustomplot.cpp \
    statchambre.cpp \
    statevenement.cpp \
    statistiq.cpp

HEADERS += \
    animation.h \
    chambre.h \
    connexion.h \
    demande.h \
    evenement.h \
    hebergement.h \
    login.h \
    mainwindow.h \
    mainwindowvideo.h \
    materiaux.h \
    notification.h \
    pdf.h \
    personnel.h \
    qcustomplot.h \
    statchambre.h \
    statevenement.h \
    statistiq.h

FORMS += \
    login.ui \
    mainwindow.ui \
    mainwindowvideo.ui \
    pdf.ui \
    statchambre.ui \
    statevenement.ui \
    statistiq.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc \
    traduction.qrc

DISTFILES += \
    historique.txt

RC_ICONS = myappico.ico
