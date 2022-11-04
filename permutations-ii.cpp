class Solution {
public:
    
    void permute(vector<vector<int>>& v , vector<int>& nums){
        sort(nums.begin() , nums.end());
        
        do{
            v.push_back(nums);
        }while(next_permutation(nums.begin() , nums.end()));
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> v;
        
        if(nums.size() == 0){
            return v;
        }
        
        permute(v , nums);
        
        return v;
    }
};