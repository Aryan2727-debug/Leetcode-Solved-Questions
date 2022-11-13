#include <bits/stdc++.h> 
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    //creating distance vector with all values as infinity
    vector<int> dist(n+1 , 1e9);
    dist[src] = 0;
    
    //running loop i.e. executing formula n-1 times
    for(int i=1;i<=n;i++){
        //traversing the edges
        for(int j=0;j<m;j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];
            
            if(dist[u] != 1e9 && (dist[u] + w < dist[v])){
                dist[v] = dist[u] + w;
            }
        }
    }
    
    //checking for negative cycle
    bool flag = false;
    for(int j=0;j<m;j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];
            
            if(dist[u] != 1e9 && (dist[u] + w < dist[v])){
                flag = true;
            }
    }
    
    if(flag == false){
        return dist[dest];
    }
    return -1;
}