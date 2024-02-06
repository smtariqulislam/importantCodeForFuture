#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Edge {
    int u, v, cost;
};

const int INF = INT_MAX;

void bellmanFord(int n, int m, vector<Edge>& edges, int source, vector<int>& dist) {
    dist[source] = 0;

    for (int i = 1; i <= n - 1; ++i) {
        for (const Edge& edge : edges) {
            if (dist[edge.u] != INF && dist[edge.u] + edge.cost < dist[edge.v]) {
                dist[edge.v] = dist[edge.u] + edge.cost;
            }
        }
    }

    // Check for negative weight cycle
    for (const Edge& edge : edges) {
        if (dist[edge.u] != INF && dist[edge.u] + edge.cost < dist[edge.v]) {
            cout << "Negative Cycle Detected" << endl;
            exit(0);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].cost;
    }

    int source;
    cin >> source;

    int q;
    cin >> q;

    for (int i = 0; i < q; ++i) {
        int destination;
        cin >> destination;

        vector<int> dist(n + 1, INF);
        bellmanFord(n, m, edges, source, dist);

        if (dist[destination] != INF) {
            cout << dist[destination] << endl;
        } else {
            cout << "Not Possible" << endl;
        }
    }

    return 0;
}
