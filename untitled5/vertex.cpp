#include "vertex.h"

Vertex::Vertex(QString key, QLabel *label, int number)
{
    this->id = key;
    this->label = label;
    this->numb = number;
}

QVector<Edge *> Vertex::get_edges(){
    return edges;
}

int Vertex::posX() {
    return label->x();
}

int Vertex::posY() {
    return label->y();
}
