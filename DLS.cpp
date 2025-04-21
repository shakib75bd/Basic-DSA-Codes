#include <iostream>
#include <vector>
#include <stack>
#include <utility> // for pair

using namespace std;

int main(){
    //basic storing of the graph(undirected)

    cout<<"Enter the number of nodes and edges: "<<endl;
    int n,e; //n=nunmber of nodes, e= number of edges
    cin>>n>>e;

    cout<<"Enter the edges (n,m): "<<endl;
    vector<int> adj[n+1]; //using adjacancy list
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);//comment this line if the graph is directed
    }

    /*DLS*/

    //declaring the started node and depth limit
    cout << "Enter starting node: ";
    int start_node;
    cin >> start_node;

    cout << "Enter depth limit: ";
    int depth_limit;
    cin >> depth_limit;

    //Marking the visited node
    vector<bool> visited(n+1,false);
    visited[start_node] = true;

    //creating stack to show DLS (store node and its depth)
    stack<pair<int,int>> myStack;
    myStack.push({start_node, 0}); // Initial depth is 0

    cout << "DLS traversal (limit=" << depth_limit << "): ";
    //traversing and showing
    while(!myStack.empty()){
        int node = myStack.top().first;
        int depth = myStack.top().second;
        myStack.pop();

        cout << node << " "; //print the node

        // Only explore further if depth is within limit
        if(depth < depth_limit) {
            // find the adjacancy node and setting the next stack top
            for(auto neighbour: adj[node]){
                if(!visited[neighbour]){
                    visited[neighbour] = true;
                    myStack.push({neighbour, depth+1}); // Increment depth
                }
            }
        }
    }
    cout << endl;

    return 0;
}
