#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to perform BFS on the graph
void BFS(int startNode, const vector<vector<int>>& adjList) {
    int numNodes = adjList.size();
    vector<bool> visited(numNodes, false);  // To track visited nodes
    queue<int> q;  // Queue for BFS

    // Start with the initial node
    visited[startNode] = true;
    q.push(startNode);

    while (!q.empty()) {
        int currentNode = q.front();
        q.pop();

        cout << currentNode << " ";  // Process the current node

        // Visit all the adjacent nodes
        for (int neighbor : adjList[currentNode]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    // Example graph represented as an adjacency list
    vector<vector<int>> adjList = {
        {1, 2},      // Node 0 is connected to nodes 1 and 2
        {0, 3, 4},   // Node 1 is connected to nodes 0, 3, and 4
        {0, 5, 6},   // Node 2 is connected to nodes 0, 5, and 6
        {1},         // Node 3 is connected to node 1
        {1},         // Node 4 is connected to node 1
        {2},         // Node 5 is connected to node 2
        {2}          // Node 6 is connected to node 2
    };

    int startNode = 0;
    cout << "BFS traversal starting from node " << startNode << ": ";
    BFS(startNode, adjList);

    return 0;
}
