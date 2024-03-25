#include "mainwindow.h"

#include <QApplication>

//#include <QDebug>
//#include <QException>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();


    /*
    QApplication a(argc, argv);
    try {

        MainWindow w;
        w.show();
        return a.exec();
    } catch (const QException &e) {
        // Captura exceções Qt
        qCritical() << "Exceção Qt capturada:" << e.what();
    } catch (const std::exception &e) {
        // Captura exceções padrão do C++
        qCritical() << "Exceção padrão capturada:" << e.what();
    } catch (...) {
        // Captura qualquer outra exceção
        qCritical() << "Exceção desconhecida capturada";
    }
    return -1; // Retorna um código de erro
    */
}
