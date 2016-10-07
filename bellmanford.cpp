#include "bellmanford.h"

BellmanFord::BellmanFord(const Graph &graph)
    : graph(graph)
{

}

vector <int> BellmanFord::runAlgorithm(int source)
{
    int size = graph.size();
    if (source >= size)
        throw std::runtime_error("Error: source not in graph.");

    const vector<Graph::Edge> edges = graph.getEdges();

    vector<int> distances(size, INT_MAX);
    distances[source] = 0;

    bool changed = true;
    int passes = 1;
    while (passes++ < size  && changed )
    {
        changed = false;
        for ( int i = 0 ; i < edges.size() ; i++ )
        {
            if ( distances[edges[i].from] != INT_MAX
                 && distances[edges[i].from] + edges[i].length
                    < distances[edges[i].to] )
            {
                distances[edges[i].to]
                        = distances[edges[i].from] + edges[i].length;
                changed = true;
            }
        }
    }

    for ( int i = 0 ; i < edges.size() ; i++ )
    {
        if ( distances[edges[i].from] != INT_MAX
             && distances[edges[i].from] + edges[i].length
                < distances[edges[i].to])
        {
            negativeWeigthCycle = true;
            return distances;
        }
    }
    negativeWeigthCycle = false;
    return distances;
}

bool BellmanFord::isNegativeWeigthCycle() const
{
    return negativeWeigthCycle;
}

