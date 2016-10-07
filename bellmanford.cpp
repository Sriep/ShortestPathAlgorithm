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

    //const int UNSET = -1;
    vector<int> distances(size, INT_MAX);
 //   vector<int> predecessors(size, UNSET);
    distances[source] = 0;

    bool changed = true;
    int passes = 1;
    while (passes++ < size  && changed )
    {
        changed = false;
        for ( int i = 0 ; i < edges.size() ; i++ )
        {
            //Graph::Edge e = edges[i];
            //int d = distances[edges[i].from] + edges[i].length;
            //int ef = distances[edges[i].to];
            if ( distances[edges[i].from] != INT_MAX
                 && distances[edges[i].from] + edges[i].length
                    < distances[edges[i].to] )
            {
                distances[edges[i].to]
                        = distances[edges[i].from] + edges[i].length;
//                predecessors[edges[i].to] = edges[i].from;
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

