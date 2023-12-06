#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
  vector<vector<int>> graph; // Adjacency list representation of the graph
  vector<bool> visited;      // Keeps track of visited nodes

public:
  // Performs Depth-First Search starting from a given node
  void dfs(int node) {
    visited[node] = true;
    cout << node << " ";

    // Traverses all adjacent nodes of the current node
    int j = 0;
    while (j < graph[node].size()) {
      int adjacentNode = graph[node][j];
      if (!visited[adjacentNode]) {
        dfs(adjacentNode);
      }
      j++;
    }
  }

  // Adds an edge between two nodes in the graph
  void addEdge(int from, int to) {
    graph[from].push_back(to); // Adds edge from 'from' to 'to'
    graph[to].push_back(
        from); // For undirected graph, adds edge from 'to' to 'from' as well
  }

  // Constructor to initialise the graph with a specified number of nodes
  Graph(int numNodes) {
    graph.resize(numNodes);
    visited.resize(numNodes, false);
  }
};

int main() {
  // Create a graph with 8 vertices
  int numNodes = 8;
  Graph graph(numNodes);

  // Adds edges between vertices
  graph.addEdge(0, 10);
  graph.addEdge(0, 2);
  graph.addEdge(1, 3);
  graph.addEdge(4, 1);
  graph.addEdge(10, 4);
  graph.addEdge(2, 3);
  graph.addEdge(1, 7);

  // Performs DFS traversal starting from node 0
  cout << "DFS traversal: ";
  graph.dfs(0);
  cout << endl;
}
