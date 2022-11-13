#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    //create adjacency list
    unordered_map <int , list<pair<int,int>> > adj;    //node with adjnode and weight
    
    for(int i=0;i<g.size();i++){
        int u = g[i].first.first;       //1st vertex
        int v = g[i].first.second;      //2nd vertex
        int w = g[i].second;            //weight between u and v
        
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    
    vector<int> key(n+1);              //initializing key array
    vector<bool> mst(n+1);             //initializing mst array
    vector<int> parent(n+1);           //initializing parent array
    
    for(int i=0;i<=n;i++){
        key[i] = INT_MAX;               //setting all values of key as infinite
        mst[i] = false;                 //setting all values of mst as false
        parent[i] = -1;                 //setting all values of parent as -1
    }
    
    key[1] = 0;                         //marking source node as 0
    parent[1] = -1;
    
    for(int i=1;i<n;i++){
        int mini = INT_MAX;
        int u;
        
        //finding minimum node
        for(int v=1;v<=n;v++){
            if(mst[v] == false && key[v] < mini){
                u = v;
                mini = key[v];
            }
        }
        
        //marking min node as true
        mst[u] = true;
        
        //checking adjacent nodes
        for(auto it : adj[u]){
            int v = it.first;
            int w = it.second;
            
            if(mst[v] == false && w < key[v]){
                parent[v] = u;
                key[v] = w;
            }
        }
    }
    vector < pair<pair<int,int> , int> > result;
    for(int i=2;i<=n;i++){
        result.push_back({{parent[i] , i} , key[i]});
    }
    
    return result;
}
