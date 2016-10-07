#include <iostream>
#include <string>
#include <map>
#include <ctime>
#include <fstream>

#include "graph.h"
#include "dijkstra.h"
#include "bellmanford.h"
#include "floydwarshall.h"

using namespace std;

void printResult(const string& filename,
                 const string& header,
                 int source,
                 const vector<int>& result,
                 clock_t time);

int main(int argc, char *argv[])
{
    try
    {
        if (argc < 2)
        {
            cout << "No filename entered\n";
            return EXIT_FAILURE;
        }
        string inFilename = argv[1];
        string outFilename = (argc >= 3) ? argv[2] : "out.txt";
        int source = (argc >= 4) ? stoul(argv[3]) : 0;

        Graph graph(inFilename);
        if (!graph.isValid())
            return EXIT_FAILURE;
        ofstream outs;
        outs.open(outFilename);
        outs << "Demo\n";
        outs << "Compare shortest path algorithms\n";
        outs.close();
        graph.printToFile(outFilename);
        if (!graph.isSymmetric())
        {
            outs.open(outFilename, ios_base::app);
            outs << "Graph is not symmetric\n";
            outs << "Only summetric graphs supported\n";
            outs << '\n';
            outs.close();
        }
        if (graph.size() > 10)
        {
            cout << "Demo restricted to graphs with less than ten nodes\n";
            return EXIT_FAILURE;
        }

        if (!graph.isNegativeEdgeWeight())
        {
            clock_t dijkstraTime = clock();
            Dijkstra dijkstra(graph);
            vector <int> dijkstraResults = dijkstra.runAlgorithm(source);
            dijkstraTime = clock() - dijkstraTime;
            printResult(outFilename,
                        "Dijkstra shortest path algorithm",
                        source,
                        dijkstraResults,
                        dijkstraTime);
        }
        else
        {
            outs.open(outFilename, ios_base::app);
            outs << "Dijkstra shortest path algorithm\n";
            outs << "Negative edge weights found\n";
            outs << "Dijkstra algorithm does not support negative edge weightings\n";
            outs << '\n';
            outs.close();
        }


        clock_t bellmanFordTime = clock();
        BellmanFord bellmanFord(graph);
        vector <int> bellmanFordResults = bellmanFord.runAlgorithm(source);
        bellmanFordTime = clock() - bellmanFordTime;
        if (!bellmanFord.isNegativeWeigthCycle())
        {
            printResult(outFilename,
                        "Bellman-Ford shortest path algorithm",
                        source,
                        bellmanFordResults,
                        bellmanFordTime);
        }
        else
        {
            outs.open(outFilename, ios_base::app);
            outs << "Bellman-Ford path algorithm\n";
            outs << "Negative weight cycle found, no solution to problem\n";
            outs << '\n';
            outs.close();
        }


        clock_t floydWarshallTime = clock();
        FloydWarshall floydWarshall(graph);
        vector <int> floydWarshallResults = floydWarshall.runAlgorithm(source);
        floydWarshallTime = clock() - floydWarshallTime;
        printResult(outFilename,
                    "Floyd-Warshall shortest path algorithm",
                    source,
                    floydWarshallResults,
                    floydWarshallTime);

        return EXIT_SUCCESS;
    }
    catch (exception e)
    {
        cout << e.what();
        return EXIT_FAILURE;
    }
}

void printResult(const string& filename,
                 const string& header,
                 int source,
                 const vector<int>& result,
                 clock_t time)
{
    ofstream outs(filename, ios_base::app);
    outs << header << '\n';
    outs << "Demo\n";
    outs << "The source node position: " << source << '\n';
    outs << "Distances" << '\n';
    for ( int i = 0 ; i < result.size() ; i++ )
    {
        outs << "Node " << i << "\tdistance: " << result[i] << '\n';
    }
    //outs << '\n' << "Time taken: " << time / CLOCKS_PER_SEC << " seconds\n";
    outs << '\n' << "Time taken: " << time  << " ms\n";
    outs << '\n';
}













