#include <iostream>
#include <vector>
#include <queue>

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
        adj[v].push_back(u);
    }

    /*BFS*/

    //declaring the started node
    cout
    int start_node;
    cin>>start_node;

    //Marking the visited node
    vector<bool> visited(n+1,false);
    visited[start_node] = true;

    //creating queue to show BFS
    queue<int> myQueue;
    myQueue.push(start_node);

    //traversing and showing
    while(!myQueue.empty()){
        int node = myQueue.front();

        cout<<node<<" "; //print the front node to show the queue

        myQueue.pop();

        // find the adjacancy node and setting the next queue front
        for(auto neighbour: adj[node]){
            if(!visited[neighbour]){
                visited[neighbour]=true;
                myQueue.push(neighbour);
            }
        }
    }
    cout<<endl;


    return 0;
}
