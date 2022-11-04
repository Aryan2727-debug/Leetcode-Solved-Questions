class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_reach = 0;
        
        for(int i=0;i<nums.size();i++){
            if((i + nums[i]) > max_reach){
                max_reach = i + nums[i];
            }
            
            if(max_reach == i){
                break;
            }
        }
        return (max_reach >= nums.size()-1);
    }
};