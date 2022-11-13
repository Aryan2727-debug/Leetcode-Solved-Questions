class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int rows = edges.size();
        int columns = edges[0].size();
        
        vector<int> v1;
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
               v1.push_back(edges[i][j]);
        }
    }
        
        for(int i=0;i<v1.size();i++){
            if(count(v1.begin() , v1.end() , v1[i]) > 1){
                return v1[i];
            }
        }
        return -1;
  }
};