#include <bits/stdc++.h>

bool cmp(vector<int> &a , vector<int> &b){
    return a[2] < b[2];
}

void makeSet(vector<int> &parent , vector<int> &rank , int n){
    for(int i=0;i<n;i++){
        parent[i] = i;
        rank[i] = 0;
    }
}

//function to find parent node
int find(vector<int> &parent , int x){
    if(parent[x] == x){
        return x;
    }
    return parent[x] = find(parent , parent[x]);       //applying path compression
}

//function for union
void unionSet(int x , int y , vector<int> &parent , vector<int> &rank){
    x = find(parent , x);
    y = find(parent , y);
    
    if(rank[x] < rank[y]){
        parent[y] = x;
    }
    
    else if(rank[y] < rank[x]){
        parent[x] = y;
    }
    
    else{
        parent[y] = x;
        rank[x]++;
    }
}

int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
    //sorting the edges vector
    sort(edges.begin() , edges.end() , cmp);
    
    //making the parent and rank arrays
    vector<int> parent(n);
    vector<int> rank(n);
    
    makeSet(parent , rank , n);
    
    int ans = 0;
    
    for(int i=0;i<edges.size();i++){
        int u = find(parent , edges[i][0]);
        int v = find(parent , edges[i][1]);
        int w = edges[i][2];
        
        if(u != v){
            ans += w;
            unionSet(u , v , parent , rank);
        }
    }
    return ans;
}