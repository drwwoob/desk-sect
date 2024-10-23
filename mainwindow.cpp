#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), petLabel(new QLabel(this)), petMovie(new QMovie(QCoreApplication::applicationDirPath() + "/../anime/zongzhu_demo.gif")), 
        centralWidget(new QWidget(this)) // Initialize central widget
    //   layout(new QVBoxLayout(centralWidget)) // Initialize layout
      {
    layout = new QVBoxLayout(centralWidget);
    // Set window flags for a frameless window and a translucent background
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    setAttribute(Qt::WA_TranslucentBackground);

    // Check if the movie is valid
    if (petMovie->isValid()) {
        petLabel->setMovie(petMovie); // Set the movie to the label
        petMovie->start(); // Start the movie

        QSize desiredSize(1200, 900); // Desired size for scaling

        // Set the fixed size for the label to the desired size
        petLabel->setFixedSize(desiredSize);
        petLabel->setScaledContents(true); // Allow the label to scale its contents

        // Resize the main window to the same size
        resize(desiredSize); // Resize the main window to the desired size

        qDebug() << "GIF loaded and started!";
    } else {
        qDebug() << "Error loading GIF!";
    }

    // =============== menu =====================
     QPushButton *imageButton = new QPushButton(this);
        QIcon buttonIcon(QCoreApplication::applicationDirPath() + "/../anime/button_file.png");
        imageButton->setIcon(buttonIcon);
        imageButton->setIconSize(QSize(100, 100)); // Adjust the size as needed

        // Connect the button's clicked signal to a slot
        connect(imageButton, &QPushButton::clicked, this, &::MainWindow::onButtonClick);

        // Add the image button to the layout
        layout->addWidget(petLabel);
    layout->addWidget(imageButton);

        setCentralWidget(centralWidget);
        // setCentralWidget(petLabel);

}


MainWindow::~MainWindow() {
    // delete petMovie;
    // delete petLabel;
    // delete layout;
    // delete centralWidget;
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

void MainWindow::onButtonClick() {
    qDebug() << "Button clicked!";
}