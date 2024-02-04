#include <iostream>
#include "graph.hpp"

Graph::Graph(int numVertices) : numVertices(numVertices) 
{
    // Initialize the adjacency matrix with zeros
    adjMatrix.resize(numVertices, std::vector<int>(numVertices, 0));
}

void Graph::addEdge(int i, int j) 
{
    adjMatrix[i][j]++;
    adjMatrix[j][i]++;
}

void Graph::removeEdge(int i, int j) 
{
    adjMatrix[i][j]--;
    adjMatrix[j][i]--;
}

int Graph::degree(int v) 
{
    int deg = 0;
    
    for (int i = 0; i < numVertices; i++)
    {
        deg += adjMatrix[v][i];
    }
        
    return deg;
}

bool Graph::isValidNextEdge(int v, int w) 
{
    // If there's no edge between v and w, return false
    if (adjMatrix[v][w] == 0)
    {
        return false;
    }

    // If v has only one adjacent vertex, then return true
    if (degree(v) == 1)
    {
        return true;
    }

    // Count reachable vertices from v
    std::vector<bool> visited(numVertices, false);
    int count1 = DFSCount(v, visited);

    // Remove edge (v, w) and after removing the edge, count vertices reachable from v
    removeEdge(v, w);
    visited = std::vector<bool>(numVertices, false);
    int count2 = DFSCount(v, visited);

    // Add the edge back to the graph
    addEdge(v, w);

    // If count1 is greater, then edge (v, w) is a bridge, do not consider this edge
    return (count1 <= count2);
}

int Graph::DFSCount(int v, std::vector<bool>& visited) 
{
    visited[v] = true;
    int count = 1;

    for (int i = 0; i < numVertices; i++)
    {
        if (adjMatrix[v][i] && !visited[i])
        {
            count += DFSCount(i, visited);
        }
    }

    return count;
}


std::pair<bool, std::vector<int>> Graph::isEulerian() 
{
    int odd = 0;
    std::vector<int> oddVertices;
    for (int i = 0; i < numVertices; i++) 
    {
        if (degree(i) & 1) 
        {
            odd++;
            oddVertices.push_back(i);
        }
    }

    // If the number of vertices with odd degree is not 2 or 0,
    // then eulerian path is not possible
    return {odd == 0 || odd == 2, oddVertices};
}

void Graph::printEulerTour() 
{
    auto eulerianInfo = isEulerian();
    
    if (!eulerianInfo.first) 
    {
        std::cout << "Eulerian path is not possible\n";
        return;
    }

    // Print Euler tour starting from first vertex with odd degree if exists, otherwise from vertex 0
    int startVertex = eulerianInfo.second.empty() ? 0 : eulerianInfo.second[0];
    printEulerUtil(startVertex);
    std::cout << std::endl;
}

void Graph::printEulerUtil(int u) 
{   
    // Go through all vertices adjacent to this
    for (int v = 0; v < numVertices; v++) 
    {
        // If edge u-v is not removed and it's a a valid next edge
        if (adjMatrix[u][v] && isValidNextEdge(u, v))
         {
            std::cout << u << "-" << v << " ";

            // Remove this edge
            removeEdge(u, v);

            // Print Euler tour starting from v
            printEulerUtil(v);
        }
    }
}