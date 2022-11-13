/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
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
    
    //code for Depth First Traversal
    
    void DFS(int node , unordered_map <int , list<int>> adj , int visited[] , vector<int> &dfs){
        visited[node] = 1;
        dfs.push_back(node);
        
        for(auto it : adj[node]){
            if(!visited[it]){
                DFS(it , adj , visited , dfs);
            }
        }
    }
    
    vector<int> DFSofGraph(int v , unordered_map <int , list<int>> adj){
        int visited[v] = {0};
        int start = 0;
        
        vector<int> dfs;
        
        DFS(start , adj , visited , dfs);
        return dfs;
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
    
    cout<<"The Depth First Traversal of the Graph is"<<endl;
    vector<int> result = g.DFSofGraph(v , g.adj);
    
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    return 0;
}