#include <QApplication>
#include "mainwindow.h"


#include <QDir>
#include <QDebug>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // qDebug() << "Current working directory:" << QDir::currentPath();

    MainWindow window;
    window.show();

    return app.exec();
}
