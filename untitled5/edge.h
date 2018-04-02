#ifndef EDGE_H
#define EDGE_H

#include "vertex.h"

class Edge
{
private:
    int weight;
    Vertex *startV;
    Vertex *endV;

    friend class Vertex;
    friend class Graph;
public:
    Vertex *get_startV();
    Vertex *get_endV();
    Edge();
    ~Edge();

};

#endif // EDGE_H
