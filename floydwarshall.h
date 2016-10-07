#ifndef FLOYDWARSHALL_H
#define FLOYDWARSHALL_H
#include <vector>

#include "graph.h"

class FloydWarshall
{
public:
    FloydWarshall(const Graph& graph);
    vector<int> runAlgorithm(int source);
    vector<vector <int>> runAlgorithmAllNodes();

private:

private:
    const Graph graph;
};

#endif // FLOYDWARSHALL_H
