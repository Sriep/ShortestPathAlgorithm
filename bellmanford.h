#ifndef BELLMANFORD_H
#define BELLMANFORD_H
#include <vector>

#include "graph.h"

class BellmanFord
{
public:
    BellmanFord(const Graph& graph);
    vector <int> runAlgorithm(int source);

    bool isNegativeWeigthCycle() const;

private:

private:
    const Graph graph;
    bool negativeWeigthCycle = false;
};

#endif // BELLMANFORD_H
