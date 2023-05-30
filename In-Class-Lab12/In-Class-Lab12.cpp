#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

vector<int> dijkstra(const vector<vector<int>>& adj_matrix, const int source) {
    int num_vertices = adj_matrix.size();
    vector<int> distances(num_vertices, numeric_limits<int>::max());
    distances[source] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, source));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (int v = 0; v < num_vertices; v++) {
            if (adj_matrix[u][v] != 0) {
                int weight = adj_matrix[u][v];
                if (distances[u] + weight < distances[v]) {
                    distances[v] = distances[u] + weight;
                    pq.push(make_pair(distances[v], v));
                }
            }
        }
    }

    return distances;
}

int main() {
    // adjacency matrix
    vector<vector<int>> adj_matrix = {
        {0, 10, 0, 0, 15, 5},
        {10, 0, 10, 30, 0, 0},
        {0, 10, 0, 12, 5, 0},
        {0, 30, 12, 0, 0, 20},
        {15, 0, 5, 0, 0, 0},
        {5, 0, 0, 20, 0, 0}
    };

    // starting city
    const int STARTINGCITY = 0;

    vector<int> distances = dijkstra(adj_matrix, STARTINGCITY);

    // Print the distances
    for (int i = 0; i < distances.size(); i++) {
        cout << "Distance from vertex " << STARTINGCITY << " to vertex " << i << " is " << distances[i] << endl;
    }

    return 0;
}
