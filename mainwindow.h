#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#pragma once

#include <QMainWindow>
#include <QLabel>
#include <QMovie>

#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMouseEvent>
#include <QDebug>


class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

private slots:

    void onButtonClick();

private:
    QLabel *petLabel;
    QMovie *petMovie;
    QPoint dragPosition;
    QVBoxLayout *layout;
    QWidget *centralWidget;


};

#endif // MAINWINDOW_H
