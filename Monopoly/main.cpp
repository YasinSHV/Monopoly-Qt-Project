#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    try{
    return a.exec();}catch(std::bad_alloc & exception){}
}
