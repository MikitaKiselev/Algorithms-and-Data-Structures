#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <fstream>

using namespace std;

long long int shortestPath(long long int n, vector<vector<pair<long long int, long long int>>>& graph) {
    vector<long long int> distances(n + 1, LLONG_MAX);
    distances[1] = 0;

    priority_queue<pair<long long int, long long int>, vector<pair<long long int, long long int>>, greater<pair<long long int, long long int>>> pq;
    pq.push({ 0, 1 });  // {distance, vertex}

    while (!pq.empty()) {
        long long int dist_u = pq.top().first;
        long long int u = pq.top().second;
        pq.pop();

        if (dist_u > distances[u]) {
            continue;
        }

        for (const auto& edge : graph[u]) {
            long long int v = edge.first;
            long long int w = edge.second;

            if (distances[u] + w < distances[v]) {
                distances[v] = distances[u] + w;
                pq.push({ distances[v], v });
            }
        }
    }

    return distances[n];
}

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    long long int n, m;
    input >> n >> m;

    vector<vector<pair<long long int, long long int>>> graph(n + 1);

    for (int i = 0; i < m; ++i) {
        long long int u, v, w;
        input >> u >> v >> w;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }

    long long int result = shortestPath(n, graph);

    output << result;

    return 0;
}