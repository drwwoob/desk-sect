#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), petLabel(new QLabel(this)), petMovie(new QMovie(QCoreApplication::applicationDirPath() + "/../anime/zongzhu_demo.gif")) {
    // Set window flags for a frameless window and a translucent background
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    setAttribute(Qt::WA_TranslucentBackground);

    // Check if the movie is valid
    if (petMovie->isValid()) {
        petLabel->setMovie(petMovie);
        
        // Wait for the movie to load and get the size of the first frame
        petMovie->start();
        QPixmap firstFrame = petMovie->currentPixmap(); // Get the current pixmap (first frame)
        
        // Check if the first frame is valid and set the size
        if (!firstFrame.isNull()) {
            QSize desiredSize(80, 60);
            QPixmap scaledPixmap = firstFrame.scaled(desiredSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
            // petLabel->setFixedSize(firstFrame.size()); // Set the label size to the first frame size
            // resize(firstFrame.size()); // Resize the main window to the same size
            qDebug() << "GIF loaded and started!";
        } else {
            qDebug() << "Error loading first frame of GIF!";
        }
    } else {
        qDebug() << "Error loading GIF!";
    }

    setCentralWidget(petLabel);  // Add petLabel to the main window
}


MainWindow::~MainWindow() {
    delete petMovie;
    delete petLabel;
}

void MainWindow::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        dragPosition = event->globalPosition().toPoint() - frameGeometry().topLeft();
        event->accept();
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event) {
    if (event->buttons() & Qt::LeftButton) {
        move(event->globalPosition().toPoint() - dragPosition);
        event->accept();
    }
}
