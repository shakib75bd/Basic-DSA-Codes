#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

bool bidirectionalBFS(int start, int goal, vector<int> adj[], int n) {
    vector<bool> visited_start(n + 1, false);
    vector<bool> visited_goal(n + 1, false);

    queue<int> q_start, q_goal;

    q_start.push(start);
    visited_start[start] = true;

    q_goal.push(goal);
    visited_goal[goal] = true;

    while (!q_start.empty() && !q_goal.empty()) {
        // Expand from start side
        int size_s = q_start.size();
        while (size_s--) {
            int current = q_start.front(); q_start.pop();
            if (visited_goal[current]) {
                cout << "Path meets at node: " << current << endl;
                return true;
            }
            for (int neighbor : adj[current]) {
                if (!visited_start[neighbor]) {
                    visited_start[neighbor] = true;
                    q_start.push(neighbor);
                }
            }
        }

        // Expand from goal side
        int size_g = q_goal.size();
        while (size_g--) {
            int current = q_goal.front(); q_goal.pop();
            if (visited_start[current]) {
                cout << "Path meets at node: " << current << endl;
                return true;
            }
            for (int neighbor : adj[current]) {
                if (!visited_goal[neighbor]) {
                    visited_goal[neighbor] = true;
                    q_goal.push(neighbor);
                }
            }
        }
    }

    return false; // No path found
}

int main() {
    cout << "Enter number of nodes and edges: ";
    int n, e;
    cin >> n >> e;

    vector<int> adj[n + 1];

    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // For undirected graph
    }

    int start, goal;
    cout << "Enter start node: ";
    cin >> start;
    cout << "Enter goal node: ";
    cin >> goal;

    if (bidirectionalBFS(start, goal, adj, n)) {
        cout << "Path found between " << start << " and " << goal << endl;
    } else {
        cout << "No path found." << endl;
    }

    return 0;
}
