#include "catch.hpp"
#include "../src/graph.hpp"

TEST_CASE("Graph initialization", "[graph]") {
    Graph g(5);
    REQUIRE(g.getNumVertices() == 5);
}

TEST_CASE("Adding and removing edges", "[graph]") {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 0);

    REQUIRE(g.degree(0) == 2);
    REQUIRE(g.degree(1) == 2);
    REQUIRE(g.degree(2) == 2);
    REQUIRE(g.degree(3) == 2);
    REQUIRE(g.degree(4) == 2);

    g.removeEdge(0, 1);
    REQUIRE(g.degree(0) == 1);
    REQUIRE(g.degree(1) == 1);
}

TEST_CASE("Eulerian path", "[graph]") {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 0);

    auto eulerianInfo = g.isEulerian();
    REQUIRE(eulerianInfo.first == true);
    REQUIRE(eulerianInfo.second.empty() == true);
}

TEST_CASE("Eulerian Path and Cycle Tests", "[Graph]") {
    SECTION("Test 1: Graph with an Eulerian path") {
        Graph g1(4);
        g1.addEdge(0, 1);
        g1.addEdge(0, 2);
        g1.addEdge(1, 2);
        g1.addEdge(2, 3);
        REQUIRE(g1.isEulerian().first == true); 
    }

    SECTION("Test 2: Graph with an Eulerian cycle") {
        Graph g2(3);
        g2.addEdge(0, 1);
        g2.addEdge(1, 2);
        g2.addEdge(2, 0);
        REQUIRE(g2.isEulerian().first == true);
    }

    SECTION("Test 3: Graph without an Eulerian path or cycle") {
        Graph g3(5);
        g3.addEdge(1, 0);
        g3.addEdge(0, 2);
        g3.addEdge(2, 1);
        g3.addEdge(0, 3);
        g3.addEdge(3, 4);
        g3.addEdge(1, 3);
        REQUIRE(g3.isEulerian().first == false);
    }
}