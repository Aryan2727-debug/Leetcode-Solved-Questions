class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        //building a graph
        vector <vector<int>> graph(n);
        
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        
        //BFS
        
        vector<int> visited(n, 0);
        visited[source] = 1;
        
        queue<int> q;
        q.push(source);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            if(node == destination){
                return true;
            }
            
            for(auto it : graph[node]){
                if(!visited[it]){
                    visited[it] = 1;
                    q.push(it);
                }
            }
        }
        return false;
    }
};