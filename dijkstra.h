#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include <map>

#include "graph.h"


class Dijkstra
{
public:
    Dijkstra(const Graph& graph);
    vector <int> runAlgorithm(int source);

private:
    int minDistance(map<int, int> intMap);

private:
    const Graph& graph;
};

#endif // DIJKSTRA_H
