#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
  int numVertices;
  vector<vector<int>> adjList;

public:
  // Initialises graph with a given number of vertices
  Graph(int numVertices) {
    this->numVertices = numVertices;
    adjList.resize(numVertices);
  }

  // Adds edge between two vertices in graph
  void addEdge(int src, int dest) {
    // Add 'dest' to the adjacency list of 'src' and vice versa to represent an
    // undirected edge
    adjList[src].push_back(dest);
    adjList[dest].push_back(src);
  }

  // Prints graph, showing the adjacency list for each vertex
  void printGraph() {
    for (int i = 0; i < numVertices; i++) {
      cout << "Adjacency list of vertex " << i << ": ";
      for (int j : adjList[i]) {
        cout << j << " ";
      }
      cout << endl;
    }
  }
};

int main() {
  // Create a graph with 5 vertices
  Graph graph(5);

  // Adds edges between vertices
  graph.addEdge(0, 1);
  graph.addEdge(0, 4);
  graph.addEdge(1, 2);
  graph.addEdge(1, 3);
  graph.addEdge(1, 4);
  graph.addEdge(2, 3);
  graph.addEdge(3, 4);

  // Prints the graph showing its adjacency lists
  graph.printGraph();
}
