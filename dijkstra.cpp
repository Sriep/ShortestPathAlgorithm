#include <stdexcept>

#include "dijkstra.h"

Dijkstra::Dijkstra(const Graph &graph)
    : graph(graph)
{
}

vector <int> Dijkstra::runAlgorithm(int source)
{
    int size = graph.size();
    if (source >= size)
        throw std::runtime_error("Error: source not in graph.");
    if (graph.isNegativeEdgeWeight())
        throw std::runtime_error("Error: Dijkstra algorithm - negative weights.");

    vector <int> visitedDistance(size, INT_MAX);
    visitedDistance[source] = 0;

    const vector<int> distancesSource = graph.row(source);
    map<int, int> unvistiedDistance;
    for ( int i = 0 ; i < size ; i++ )
    {
        if ( i != source )
        {
            if ( distancesSource[i] == 0 )
                unvistiedDistance[i] = INT_MAX;
            else
                unvistiedDistance[i] = distancesSource[i];
        }
    }

    while ( !unvistiedDistance.empty() )
    {
        int target = minDistance(unvistiedDistance);
        int targetDistance = unvistiedDistance[target];
        visitedDistance[target] = targetDistance;
        unvistiedDistance.erase(target);

        const vector<int> dTarget = graph.row(target);
        for ( auto it = unvistiedDistance.cbegin()
              ; it != unvistiedDistance.cend()
              ; it++ )
        {
            if ( dTarget[it->first] > 0
                 && targetDistance + dTarget[it->first] < it->second )
            {
                unvistiedDistance[it->first]
                        = targetDistance + dTarget[it->first];
            }
        }
    }

    return visitedDistance;
}

int Dijkstra::minDistance(map<int, int> intMap)
{
    int minValue = INT_MAX;
    int minKey = INT_MAX;
    for ( auto it = intMap.cbegin() ; it != intMap.cend() ; it++ )
    {
        if (it->second < minValue)
        {
            minKey = it->first;
            minValue = it->second;
        }
    }
    if (INT_MAX == minKey)
        throw std::runtime_error("Error: disjoint graph.");
    return minKey;
}
