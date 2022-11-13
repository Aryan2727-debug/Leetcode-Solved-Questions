#include <bits/stdc++.h> 

void topoSort(int node , vector<bool> &visited , stack<int> &s , unordered_map<int , list<int>> adj){
    visited[node] = 1;
    
    for(auto it : adj[node]){
        if(!visited[it]){
            topoSort(it , visited , s , adj);
        }
    }
    s.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // creating adjacency list
    unordered_map < int , list<int> > adj;
    
    for(int i=0;i<e;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
    }
    
    //creating visited vector
    vector <bool> visited(v);
    //creating a stack
    stack<int> s;
    
    for(int i=0;i<v;i++){
        if(!visited[i]){
            topoSort(i , visited , s , adj);
        }
    }
    
    vector<int> ans;
    
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    
    return ans;
}