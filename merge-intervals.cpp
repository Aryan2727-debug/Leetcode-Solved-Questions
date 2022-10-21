class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector <vector<int>> result;
        
        //base case
        if(intervals.size() == 0){
            return result;
        }
        
        //sorting the given matrix
        sort(intervals.begin() , intervals.end());
        
        //inserting the 1st interval into new matrix
        result.push_back(intervals[0]);
        
        int j = 0;
        
        
        for(int i=1;i<intervals.size();i++){
            
 /*if 2nd element of 1st array of new matrix >= 1st element of 1st array of intervals,
 then the 2nd element of 1st array of new matrix = max(both vectors)*/           
            
            if(result[j][1] >= intervals[i][0]){
                result[j][1] = max(result[j][1] , intervals[i][1]);
            }
            else{
                j++;
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};