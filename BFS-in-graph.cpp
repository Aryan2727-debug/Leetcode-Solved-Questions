
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Graph{
    public:
    unordered_map <int , list<int>> adj;
    
    void addEdge(int u , int v , bool direction){
        adj[u].push_back(v);
        
        if(direction == 0){
            adj[v].push_back(u);
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
    
    //code for Breadth First Traversal
    
    void BFS(int v , unordered_map<int , list<int>> adj){
        int visited[v] = {0};
        visited[0] = 1;
        
        queue <int> q;
        q.push(0);
        
        vector<int> bfs;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            
            for(auto it : adj[node]){
                if(!visited[it]){
                    visited[it] = 1;
                    q.push(it);
                }
            }
        }
        for(int i=0;i<bfs.size();i++){
            cout<<bfs[i]<<" ";
        }
    }
    
};

int main()
{
    int v;
    cout<<"Enter the number of vertices"<<endl;
    cin>>v;
    
    int e;
    cout<<"Enter the number of edges"<<endl;
    cin>>e;
    
    Graph g;
    
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        
        g.addEdge(u,v,0);
    }
    
    g.print();
    
    g.BFS(v , g.adj);
    return 0;
}