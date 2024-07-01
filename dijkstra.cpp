#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> shortestPath(int n, vector<vector<int>>& edges) {
        vector<pair<int,int>> adj[n+1];
        for (auto it: edges) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(n+1, numeric_limits<int>::max()), path(n+1, -1);
        dist[1] = 0;
        pq.push({0, 1});

        while (!pq.empty()) {
            auto current = pq.top();
            pq.pop();
            int node = current.second;
            int distance = current.first;

            if (distance > dist[node])
                continue; // Skip if not a shortest path

            for (auto it : adj[node]) {
                int adjNode = it.first;
                int edgeWeight = it.second;

                if (dist[node] + edgeWeight < dist[adjNode]) {
                    dist[adjNode] = dist[node] + edgeWeight;
                    path[adjNode] = node; // Store parent for path reconstruction
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        if (dist[n] == numeric_limits<int>::max())
            return {-1};

        vector<int> shortestPath;
        for (int node = n; node != -1; node = path[node])
            shortestPath.push_back(node);
        reverse(shortestPath.begin(), shortestPath.end());

        return shortestPath;
    }
};


