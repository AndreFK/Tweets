#ifndef GRAPH_H
#define GRAPH_H

#include <QVector>
#include <QString>
#include <QPainter>
#include <QPoint>

#include "vertex.h"
#include "edge.h"

class Graph
{
private:
    QVector<Vertex *> vertexes;
    int num_of_Vertex;
    friend class Vertex;
    friend class Edge;
public:
    Graph();
    void addV(QString, QLabel *);
    void addEdg(QString starV, QString endV, int weight);
    void addEdg(Vertex *vert_start, Vertex *vert_end, int weight);
    int get_Num_of_Vertex();
    QVector<Vertex *> get_Vertexes();
};

#endif // GRAPH_H
