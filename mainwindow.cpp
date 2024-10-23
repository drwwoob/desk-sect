#include "mainwindow.h"
#include "customizeButton.h"

#include <QApplication>
#include <QMouseEvent>
#include <QDebug>
#include <Qfile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      petLabel(new QLabel(this)),
      petMovie(new QMovie(QCoreApplication::applicationDirPath() + "/../anime/zongzhu_demo.gif")),
      centralWidget(new QWidget(this)) // Initialize central widget
                                       //   layout(new QVBoxLayout(centralWidget)) // Initialize layout
{
    layout = new QVBoxLayout(centralWidget);
    // Set window flags for a frameless window and a translucent background
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    setAttribute(Qt::WA_TranslucentBackground);

    QFile file(QCoreApplication::applicationDirPath() + "/../styles.qss");
    if (file.open(QFile::ReadOnly))
    {
        QTextStream stream(&file);
        QString stylesheet = stream.readAll();
        qApp->setStyleSheet(stylesheet); // Apply the stylesheet to the whole application
        file.close();
    }
    else
    {
        qDebug() << "Could not open stylesheet file!";
    }

    // Check if the movie is valid
    if (petMovie->isValid())
    {
        petLabel->setMovie(petMovie); // Set the movie to the label
        petMovie->start();            // Start the movie

        QSize desiredSize(1200, 900); // Desired size for scaling

        // Set the fixed size for the label to the desired size
        petLabel->setFixedSize(desiredSize);
        petLabel->setScaledContents(true); // Allow the label to scale its contents

        // Resize the main window to the same size
        resize(desiredSize); // Resize the main window to the desired size

        qDebug() << "GIF loaded and started!";
    }
    else
    {
        qDebug() << "Error loading GIF!";
    }

    // =============== menu =====================
    //     file_button = new QPushButton(this);
    //     file_button->setObjectName("file_button");
    //     QIcon buttonIcon(QCoreApplication::applicationDirPath() + "/../anime/button_file.png");
    //     file_button->setIcon(buttonIcon);
    //     file_button->setIconSize(QSize(100, 100)); // Adjust the size as needed
    //     file_button->setFlat(true);
    //     file_button->setStyleSheet("background: transparent;");

    // // Position the button manually if needed
    //     file_button->move(50, 50);
    //     // Connect the button's clicked signal to a slot
    //     connect(file_button, &QPushButton::clicked, this, &::MainWindow::onButtonClick);
    
auto *file_button = new CustomizeButton(
    QCoreApplication::applicationDirPath() + "/../anime/button_file.png",
    QCoreApplication::applicationDirPath() + "/../anime/button_file_hover.png",
    QCoreApplication::applicationDirPath() + "/../anime/button_file_toggle.png",
    QCoreApplication::applicationDirPath() + "/../anime/button_file_pressed.png", // Path for pressed icon
    this
);

    file_button->setObjectName("file_button");
    file_button->setIconSize(QSize(100, 100));
    // file_button->setStyleSheet("background: transparent;");
    layout->addWidget(file_button);

    // Add the gif & image button to the layout
    layout->addWidget(petLabel);
    // layout->addWidget(file_button);

    setCentralWidget(centralWidget);
}

// MainWindow::~MainWindow()
// {
//     // delete petMovie;
//     // delete petLabel;
//     // delete layout;
//     // delete centralWidget;
// }

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        dragPosition = event->globalPosition().toPoint() - frameGeometry().topLeft();
        event->accept();
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton)
    {
        move(event->globalPosition().toPoint() - dragPosition);
        event->accept();
    }
}
void MainWindow::onButtonClick() {
}
