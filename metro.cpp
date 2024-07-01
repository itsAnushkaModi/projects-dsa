#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm> // For std::reverse

using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int destination;
    int weight;
    // Constructor for better readability and initialization
    Edge(int dest, int w) : destination(dest), weight(w) {}
};

// Function to find the shortest path using Dijkstra's algorithm
vector<int> shortestPath(int source, int destination, const vector<vector<Edge>>& graph) {
    int numStations = graph.size();
    vector<int> dist(numStations, numeric_limits<int>::max());
    vector<int> parent(numStations, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (const Edge& edge : graph[u]) {
            int v = edge.destination;
            int weight = edge.weight;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    // Check if the destination is reachable
    if (dist[destination] == numeric_limits<int>::max()) {
        cout << "Destination is not reachable from the source." << endl;
        return vector<int>(); // Return an empty path
    }

    // Reconstruct the shortest path
    vector<int> path;
    for (int v = destination; v != -1; v = parent[v])
        path.push_back(v);
    reverse(path.begin(), path.end());
    
    return path;
}

int main() {
    // Example metro network represented as an adjacency list
    vector<vector<Edge>> graph = {
        // Station 0
        {{1, 5}, {2, 3}},
        // Station 1
        {{0, 5}, {3, 7}},
        // Station 2
        {{0, 3}, {3, 4}},
        // Station 3
        {{1, 7}, {2, 4}}
    };

    int source = 0;
    int destination = 3;

    vector<int> shortest = shortestPath(source, destination, graph);

    if (!shortest.empty()) {
        cout << "Shortest path from station " << source << " to station " << destination << ": ";
        for (int station : shortest)
            cout << station << " ";
        cout << endl;
    }

    return 0;
}