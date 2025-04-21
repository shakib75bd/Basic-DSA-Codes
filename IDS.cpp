#include <iostream>
#include <vector>
#include <stack>
#include <utility> // for pair

using namespace std;

// Function for Depth-Limited Search
bool depthLimitedSearch(vector<int> adj[], int start_node, int goal_node, int depth_limit, int n) {
    vector<bool> visited(n+1, false);
    visited[start_node] = true;

    stack<pair<int,int>> myStack;
    myStack.push({start_node, 0}); // Initial depth is 0

    cout << "  DLS with limit " << depth_limit << ": ";
    bool goalFound = false;

    while(!myStack.empty()) {
        int node = myStack.top().first;
        int depth = myStack.top().second;
        myStack.pop();

        cout << node << " "; // print the node

        if(node == goal_node) {
            goalFound = true;
            // Continue traversal to explore all nodes within depth limit
        }

        // Only explore further if depth is within limit
        if(depth < depth_limit) {
            // find the adjacency nodes and setting the next stack top
            for(auto neighbour: adj[node]) {
                if(!visited[neighbour]) {
                    visited[neighbour] = true;
                    myStack.push({neighbour, depth+1}); // Increment depth
                }
            }
        }
    }
    cout << endl;
    return goalFound;
}

int main() {
    // Basic storing of the graph(undirected)
    cout << "Enter the number of nodes and edges: " << endl;
    int n, e; // n=number of nodes, e=number of edges
    cin >> n >> e;

    cout << "Enter the edges (u,v): " << endl;
    vector<int> adj[n+1]; // using adjacency list
    for(int i=0; i<e; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u); // comment this line if the graph is directed
    }

    /* Iterative Deepening Search */

    // Declaring the start and goal nodes
    cout << "Enter starting node: ";
    int start_node;
    cin >> start_node;

    cout << "Enter goal node: ";
    int goal_node;
    cin >> goal_node;

    cout << "Enter maximum depth to search: ";
    int max_depth;
    cin >> max_depth;

    cout << "Iterative Deepening Search from " << start_node << " to " << goal_node << ":" << endl;
    bool found = false;

    // Incrementally increase depth limit from 0 to max_depth
    for(int depth = 0; depth <= max_depth; depth++) {
        cout << "Depth limit = " << depth << endl;
        found = depthLimitedSearch(adj, start_node, goal_node, depth, n);

        if(found) {
            cout << "Goal node " << goal_node << " found at depth " << depth << endl;
            break;
        }
    }

    if(!found) {
        cout << "Goal node not found within maximum depth " << max_depth << endl;
    }

    return 0;
}
