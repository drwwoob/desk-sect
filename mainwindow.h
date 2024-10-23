#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#pragma once

#include <QMainWindow>
#include <QLabel>
#include <QMovie>
#include <QVBoxLayout>
#include <QPushButton>
#include "customizeButton.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() = default;

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

private slots:

    void onButtonClick();

private:
    CustomizeButton *file_button;
    QLabel *petLabel;
    QMovie *petMovie;
    QPoint dragPosition;
    QVBoxLayout *layout;
    QWidget *centralWidget;


};

#endif // MAINWINDOW_H
