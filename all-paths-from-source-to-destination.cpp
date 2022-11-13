class Solution {
public:
    
    vector<vector<int>> result;
    
    void dfs(vector<vector<int>> &graph , int vertex , vector<int> v={}){
        v.push_back(vertex);
        
        if(vertex == size(graph)-1){
            result.push_back(v);
            return;
        }
        
        for(auto it : graph[vertex]){
            dfs(graph,it,v);
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        dfs(graph,0,{});
        
        return result;
    }
};