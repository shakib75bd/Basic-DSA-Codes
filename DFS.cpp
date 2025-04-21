#include <iostream>
#include <vector>
#include <stack>

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

    /*DFS*/

    //declaring the started node
    cout << "Enter starting node: ";
    int start_node;
    cin>>start_node;

    //Marking the visited node
    vector<bool> visited(n+1,false);
    visited[start_node] = true;

    //creating stack to show DFS (changed from queue)
    stack<int> myStack;
    myStack.push(start_node);

    cout << "DFS traversal: ";
    //traversing and showing
    while(!myStack.empty()){
        int node = myStack.top(); // Changed from front() to top()

        cout<<node<<" "; //print the top node

        myStack.pop();

        // find the adjacancy node and setting the next stack top
        for(auto neighbour: adj[node]){
            if(!visited[neighbour]){
                visited[neighbour]=true;
                myStack.push(neighbour);
            }
        }
    }
    cout<<endl;

    return 0;
}
