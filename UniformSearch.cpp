#include <iostream>
#include <vector>
#include <queue>
#include <utility> // for pair

using namespace std;

int main(){
    cout << "Enter the number of nodes and edges: " << endl;
    int n, e;
    cin >> n >> e;

    cout << "Enter the edges with cost (u v cost): " << endl;
    vector<pair<int, int>> adj[n+1]; // adjacency list with cost
    for(int i = 0; i < e; i++){
        int u, v, cost;
        cin >> u >> v >> cost;
        adj[u].push_back({v, cost});
        adj[v].push_back({u, cost}); // remove if graph is directed
    }

    cout << "Enter starting node: ";
    int start_node;
    cin >> start_node;

    // Priority queue to get the minimum cost node first (min-heap)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start_node}); // {cost, node}

    vector<bool> visited(n + 1, false);

    cout << "Uniform Cost Search Traversal: ";
    while(!pq.empty()){
        int cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(visited[node]) continue;
        visited[node] = true;

        cout << node << " (cost: " << cost << ") ";

        for(auto edge : adj[node]){
            int neighbor = edge.first;
            int edge_cost = edge.second;

            if(!visited[neighbor]){
                pq.push({cost + edge_cost, neighbor});
            }
        }
    }

    cout << endl;
    return 0;
}
