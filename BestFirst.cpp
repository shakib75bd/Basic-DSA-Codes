#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

struct Node {
    int vertex;
    int h; // heuristic value

    bool operator>(const Node& other) const {
        return h > other.h;
    }
};

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
    vector<bool> visited(n + 1, false);
    vector<int> parent(n + 1, -1);

    pq.push({start, heuristic[start]});

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        int node = current.vertex;

        if (visited[node]) continue;
        visited[node] = true;

        cout << "Visiting: " << node << endl;

        if (node == goal) {
            cout << "Goal found!" << endl;
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

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                parent[neighbor] = node;
                pq.push({neighbor, heuristic[neighbor]});
            }
        }
    }

    cout << "Goal not reachable." << endl;
    return 0;
}
