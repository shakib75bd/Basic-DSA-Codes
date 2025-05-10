#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits>

using namespace std;

int main() {
    int n, e;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> e;

    vector<vector<int>> adj(n + 1);

    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // remove if directed
    }

    unordered_map<int, int> heuristic;
    cout << "Enter heuristic values (node h):" << endl;
    for (int i = 0; i < n; i++) {
        int node, h;
        cin >> node >> h;
        heuristic[node] = h;
    }

    int start, goal;
    cout << "Enter start and goal nodes: ";
    cin >> start >> goal;

    int current = start;
    vector<int> path = {current};

    while (current != goal) {
        int best_neighbor = -1;
        int best_h = heuristic[current];

        for (int neighbor : adj[current]) {
            if (heuristic[neighbor] < best_h) {
                best_h = heuristic[neighbor];
                best_neighbor = neighbor;
            }
        }

        if (best_neighbor == -1) {
            cout << "Stuck at local optimum. Search failed." << endl;
            return 0;
        }

        current = best_neighbor;
        path.push_back(current);
    }

    cout << "Goal reached using Hill Climbing!" << endl;
    cout << "Path: ";
    for (int node : path) cout << node << " ";
    cout << endl;

    return 0;
}
