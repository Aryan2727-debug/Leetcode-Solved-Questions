#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Graph{
    public:
    unordered_map < int , list<int> > adj;
    
    void addEdge(int u , int v , bool direction){
        
        //if direction = 0 => Undirected Graph
        //if direction = 1 => Directed Graph
        
        //create an Edge from u to v
        
        adj[u].push_back(v);
        
        if(direction == 0){
            adj[v].push_back(u);       //for Undirected Graph
        }
    }
    
    void print(){
        for(auto i : adj){
            cout<<i.first<<"->";
            for(auto j : i.second){
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }
};

int main()
{
    int n;
    cout<<"Enter the number of Nodes"<<endl;
    cin>>n;
    
    int e;
    cout<<"Enter the number of Edges"<<endl;
    cin>>e;
    
    Graph g;
    
    cout<<"Enter the values of nodes and edges"<<endl;
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        //creating an undirected graph
        
        g.addEdge(u , v , 0);
    }
    
    //printing the graph
    
    cout<<"The Adjacency List is"<<endl;
    g.print();
    return 0;
}
