#ifndef VERTEX_H
#define VERTEX_H

#include <QString>
#include <QVector>
#include <QLabel>

class Edge;

class Vertex
{
private:
    QString id;
    int numb;
    QLabel *label;
    QVector<Edge *> edges;
    friend class Edge;
    friend class Graph;
public:
    Vertex(QString, QLabel *, int);
    ~Vertex();
    QVector<Edge *> get_edges();
    int posX();
    int posY();
};

#endif // VERTEX_H
