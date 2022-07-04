#include "mainwindow.h"

#include <QApplication>
#include <iostream>

#include "module1.h"
#include "module2.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    Module1Class module1;
    Module2Class module2;

    std::cout << "Module1Class: " << module1.AddInt(2, 3) << std::endl;
    std::cout << "Module2Class: " << module2.MultiplyDouble(-3.55, 2.89) << std::endl;

    w.show();
    return a.exec();
}
