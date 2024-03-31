QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    clientes.cpp \
    encomendas.cpp \
    expedicao.cpp \
    listaprodutos.cpp \
    main.cpp \
    mainwindow.cpp \
    producao.cpp \
    stockprodutos.cpp

HEADERS += \
    QuantidadeDelegate.h \
    ReportDialog.h \
    clientes.h \
    encomendas.h \
    expedicao.h \
    listaprodutos.h \
    mainwindow.h \
    producao.h \
    stockprodutos.h

FORMS += \
    clientes.ui \
    encomendas.ui \
    expedicao.ui \
    listaprodutos.ui \
    mainwindow.ui \
    producao.ui \
    stockprodutos.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    imagens.qrc

DISTFILES += \
    img/Captura de ecrã 2024-03-13 193909.png
