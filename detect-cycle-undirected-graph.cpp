class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    bool dfs(int S, int parent, vector<int> adj[], vector<bool> &visited){
        visited[S] = true;
        
        for(auto it : adj[S]){
            if(!visited[it]){
                if(dfs(it , S , adj , visited)){
                 return true;
                }
            }else if(it != parent){
                return true;
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V,false);
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                bool f = dfs(i , -1 , adj , visited);
                
                if(f){
                    return true;
                }
            }
        }
        return false;
    }
};