#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QByteArray>
#include <QLabel>
#include <QPainter>
#include <QPixmap>
#include <QPoint>
#include <QPaintEvent>
#include <iostream>

#include "graph.h"
#include "vertex.h"
#include "edge.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    friend class Graph;
    void drawV(int, int, QString);

private slots:
    void on_pushButtonBuscar_clicked();

    void on_pushButtonMostrar_clicked();

private:
    Ui::MainWindow *ui;
    Graph * graph;
    QVector<Qpoint> starting_point;
    QVector<QPoint> end_point;

protected:
    void paintEvent(QPaintEvent*e);
};

#endif // MAINWINDOW_H
