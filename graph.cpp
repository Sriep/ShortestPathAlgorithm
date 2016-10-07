#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>

#include "graph.h"

Graph::Graph(const string& filename)
    : filename(filename)
{
    init();
    symmetric = checkSymmetric();
}

int Graph::edge(int row, int col) const
{
    return graph[row][col];
}

bool Graph::isValid()
{
    return valid;
}

const vector<int> Graph::row(int row) const
{
    return graph[row];
}

int Graph::size() const
{
    return graph.size();
}

const vector<Graph::Edge> Graph::getEdges() const
{
    return edges;
}

bool Graph::isNegativeEdgeWeight() const
{
    return negativeEdgeWeight;
}

void Graph::init()
{
    valid = readGraph();
}

bool Graph::isSymmetric() const
{
    return symmetric;
}

void Graph::printToFile(const string& outFilename)
{
    ofstream outs(outFilename, ios_base::app);
    outs << "Graph in matrix form, each value is an edge weight\n";
    for ( int row = 0 ; row < graph.size() ; row++ )
    {
       for ( int col = 0 ; col < graph.size() ; col++)
       {
           outs << '\t' << (int) graph[row][col];
       }
       outs << '\n';
    }
    outs << '\n';
}

bool Graph::readGraph()
{
    ifstream inFileStream(filename);
    if (!inFileStream)
    {
        cout<< "File opening failed\n";
        return false;
    }

    string line;
    while (getline(inFileStream, line))
    {
        stringstream sstream(line);
        graph.push_back( readRow(sstream) );
    }
    setEdges();
    return true;

}

vector<int> Graph::readRow(stringstream& sstream )
{
    vector<int> row;

    if (sstream.peek() == ' ')
        sstream.ignore();
    int edge;
    while( sstream >> edge)
    {
        row.push_back(edge);
        if (edge < 0)
            negativeEdgeWeight = true;
        if (sstream.peek() == ',' || sstream.peek() == ' ')
            sstream.ignore();
    }
    return row;
}

void Graph::setEdges()
{
    for ( int row = 0 ; row < graph.size() ; row++ )
    {
       for ( int col = 0 ; col < graph.size() ; col++)
       {
           if (0 != graph[row][col])
           {
                Edge edge = {row, col, graph[row][col]};
                edges.push_back(edge);
           }
       }
    }
}

bool Graph::checkSymmetric() const
{
    for ( int row = 0 ; row < graph.size() ; row++ )
    {
       for ( int col = 0 ; col < graph.size() ; col++)
       {
           if (graph[col][row] != graph[row][col])
           {
                return false;
           }
       }
    }
    return true;
}













