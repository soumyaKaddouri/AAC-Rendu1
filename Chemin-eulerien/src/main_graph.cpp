#include <iostream>
#include "graph.hpp" 

int main() {
    // Test 1: Graphe avec un chemin eulerien
    Graph g1(4);
    g1.addEdge(0, 1);
    g1.addEdge(0, 2);
    g1.addEdge(1, 2);
    g1.addEdge(2, 3);
    std::cout << "Test 1: ";
    g1.printEulerTour();

    // Test 2: Graphe avec un cycle eulerien
    Graph g2(3);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 0);
    std::cout << "Test 2: ";
    g2.printEulerTour();

    // Test 3: Graphe sans chemin ni cycle eulerien
    Graph g3(5);
    g3.addEdge(1, 0);
    g3.addEdge(0, 2);
    g3.addEdge(2, 1);
    g3.addEdge(0, 3);
    g3.addEdge(3, 4);
    g3.addEdge(1, 3);
    std::cout << "Test 3: ";
    g3.printEulerTour();

    // Test 4: Graphe avec un sommet isolé
    Graph g4(3);
    g4.addEdge(0, 1);
    std::cout << "Test 4: ";
    g4.printEulerTour();

    return 0;
}