#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

// f = g + h
struct Node {
    int vertex;
    int cost;       // g(n): cost from start
    int f;          // total cost = g(n) + h(n)

    bool operator>(const Node& other) const {
        return f > other.f;
    }
};

int main() {
    int n, e;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> e;

    vector<pair<int, int>> adj[n + 1]; // (neighbor, weight)

    cout << "Enter edges (u v cost):" << endl;
    for (int i = 0; i < e; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        adj[u].push_back({v, cost});
        adj[v].push_back({u, cost}); // remove if directed
    }

    // Heuristic values h(n) for each node
    unordered_map<int, int> heuristic;
    cout << "Enter heuristic for each node (node h):" << endl;
    for (int i = 0; i < n; i++) {
        int node, h;
        cin >> node >> h;
        heuristic[node] = h;
    }

    int start, goal;
    cout << "Enter start and goal nodes: ";
    cin >> start >> goal;

    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push({start, 0, heuristic[start]});

    vector<bool> visited(n + 1, false);
    vector<int> parent(n + 1, -1);

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        int node = current.vertex;
        int g = current.cost;

        if (visited[node]) continue;
        visited[node] = true;

        if (node == goal) {
            cout << "Goal found with total cost: " << g << endl;
            // Reconstruct path
            vector<int> path;
            while (node != -1) {
                path.push_back(node);
                node = parent[node];
            }
            reverse(path.begin(), path.end());
            cout << "Path: ";
            for (int p : path) cout << p << " ";
            cout << endl;
            return 0;
        }

        for (auto [neighbor, weight] : adj[node]) {
            if (!visited[neighbor]) {
                parent[neighbor] = node;
                int new_cost = g + weight;
                int f = new_cost + heuristic[neighbor];
                pq.push({neighbor, new_cost, f});
            }
        }
    }

    cout << "Goal not reachable from start node." << endl;
    return 0;
}
