#ifndef ALGO_HPP
#define ALGO_HPP

#include <vector>

/**
 * @brief A class to represent a Graph using an adjacency matrix.
 */
class Graph 
{

private:

    std::vector<std::vector<int>> adjMatrix; ///< Adjacency matrix to represent the graph
    int numVertices; ///< Number of vertices in the graph

public:
    /**
     * @brief Construct a new Graph object
     * 
     * @param numVertices Number of vertices in the graph
     */
    Graph(int numVertices);

    /**
     * @brief Add an edge between two vertices
     * 
     * @param i First vertex
     * @param j Second vertex
     */
    void addEdge(int i, int j);

    /**
     * @brief Remove an edge between two vertices
     * 
     * @param i First vertex
     * @param j Second vertex
     */
    void removeEdge(int i, int j);

    /**
     * @brief Get the degree of a vertex
     * 
     * @param v Vertex
     * @return int Degree of the vertex
     */
    int degree(int v);

    /**
     * @brief Check if edge from v to w is a valid next edge in Euler tour/path
     * 
     * @param v First vertex
     * @param w Second vertex
     * @return true If the edge is a valid next edge
     * @return false Otherwise
     */
    bool isValidNextEdge(int v, int w);

    /**
     * @brief A DFS based function to count reachable vertices from v
     * 
     * @param v The vertex
     * @param visited A vector to keep track of visited vertices
     * @return The count of reachable vertices
     */
    int DFSCount(int v, std::vector<bool>& visited);

    /**
     * @brief Check if the graph is Eulerian
     * 
     * @return std::pair<bool, std::vector<int>> A pair containing a boolean indicating if the graph is Eulerian and a vector containing the vertices of the Eulerian tour
     */
    std::pair<bool, std::vector<int>> isEulerian();

    /**
     * @brief Print Euler tour starting from vertex u
     */
    void printEulerTour();

    /**
     * @brief Recursive function to print Euler tour from vertex u
     * 
     * @param u The vertex
     */
    void printEulerUtil(int u);

    /**
     * @brief Get the number of vertices in the graph
     * 
     * @return int Number of vertices
     */
    int getNumVertices() const { return numVertices; }
};

#endif // ALGO_HPP