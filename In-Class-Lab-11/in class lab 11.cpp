#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> Edge;
typedef vector<vector<Edge>> Graph;

// Function to add an edge to the graph
void addEdge(Graph& graph, int u, int v, int weight) {
    graph[u].push_back(make_pair(v, weight));
    graph[v].push_back(make_pair(u, weight));
}

// Function to find the minimum spanning tree using Prim's algorithm
void primMST(const Graph& graph, int startVertex) {
    int numVertices = graph.size();

    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

    vector<int> distance(numVertices, INT_MAX);
    vector<bool> visited(numVertices, false);
    vector<int> parent(numVertices, -1);

    pq.push(make_pair(0, startVertex));
    distance[startVertex] = 0;

    while (true) {
        int minDistance = INT_MAX;
        int minVertex = -1;

        // Find the vertex with the minimum distance that is not yet visited
        for (int v = 0; v < numVertices; v++) {
            if (!visited[v] && distance[v] < minDistance) {
                minDistance = distance[v];
                minVertex = v;
            }
        }

        if (minVertex == -1) {
            // All vertices have been visited
            break;
        }

        visited[minVertex] = true;

        // Process the neighbors of the minimum distance vertex
        for (const auto& neighbor : graph[minVertex]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (!visited[v] && weight < distance[v]) {
                distance[v] = weight;
                parent[v] = minVertex;
                pq.push(make_pair(distance[v], v));
            }
        }
    }

    // Print the minimum spanning tree
    cout << "Edges in the Minimum Spanning Tree:" << endl;
    for (int v = 1; v < numVertices; v++) {
        cout << parent[v] << " --- " << v << "         weight  : " << distance[v] << endl;
    }
}

int main() {
    int numVertices = 6;
    Graph graph(numVertices);

    // Adding edges to the graph
    addEdge(graph, 0, 5, 1);
    addEdge(graph, 1, 3, 1);
    addEdge(graph, 1, 2, 2);
    addEdge(graph, 0, 1, 3);
    addEdge(graph, 2, 3, 3);
    addEdge(graph, 4, 5, 4);
    addEdge(graph, 2, 5, 5);
    addEdge(graph, 3, 4, 5);
    addEdge(graph, 1, 4, 10);

    int startVertex = 0;
    primMST(graph, startVertex);

    return 0;
}
