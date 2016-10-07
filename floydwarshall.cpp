#include "floydwarshall.h"

FloydWarshall::FloydWarshall(const Graph &graph)
    : graph(graph)
{

}

vector<int> FloydWarshall::runAlgorithm(int source)
{
    vector<vector <int>> allDistances = runAlgorithmAllNodes();
    return allDistances[source];
}

vector<vector <int>> FloydWarshall::runAlgorithmAllNodes()
{
    int size = graph.size();

    vector<vector<int>> distances(size, vector<int>(size, INT_MAX));
    const vector<Graph::Edge> edges = graph.getEdges();
    for ( int i = 0 ; i < edges.size() ; i++ )
    {
        distances[edges[i].from][edges[i].to] = edges[i].length;
    }
    for ( int i = 0 ; i < size ; i++ )
    {
        distances[i][i] = 0;
    }


    for ( int i = 0 ; i < size ; i++ )
    {
        for ( int j = 0 ; j < size ; j++ )
        {
            for ( int k = 0 ; k < size ; k++ )
            {
                if ( distances[j][i] != INT_MAX
                     && distances[i][k] != INT_MAX
                     && (distances[j][k] > distances[j][i] + distances[i][k]) )
                {
                    distances[j][k] = distances[j][i] + distances[i][k];
                }
            }
        }
    }

    return distances;
}
