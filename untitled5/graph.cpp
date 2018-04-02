#include "graph.h"

Graph::Graph()
{
    num_of_Vertex = 0;
}

void Graph::addV(QString id, QLabel *label)
{
    vertexes.push_back(new Vertex(id, label, num_of_Vertex));
    num_of_Vertex++;
}

void Graph::addEdg(QString vertex1, QString vertex2, int weight)
{
    int count = 0;
    int tmp;
    Edge *edge = new Edge();
    for(int i = 0; i < vertexes.size(); i++) {
        if(vertexes[i]->id == vertex1) {
            edge->startV = vertexes[i];
            tmp = i;
            count++;
        }
        if(vertexes[i]->id == vertex2) {
            edge->endV = vertexes[i];
            count++;
        }
    }
    if(count < 2) {

        return;
    }
    else {
        edge->weight = weight;
        vertexes[tmp]->edges.push_back(edge);
    }
}

void Graph::addEdg(Vertex *origin, Vertex *destiny, int weight)
{
    Edge *edge = new Edge();
    edge->startV = origin;
    edge->endV = destiny;
    edge->weight = weight;
    origin->edges.push_back(edge);
}

int Graph::get_Num_of_Vertex(){
    return num_of_Vertex;
}

QVector<Vertex *> Graph::get_Vertexes(){
    return vertexes;
}
