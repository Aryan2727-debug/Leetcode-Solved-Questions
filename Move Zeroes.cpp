class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> result;
        for(int i=0;i<nums.size();i++){
            if(nums[i] != 0){
                result.push_back(nums[i]);
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0){
                result.push_back(nums[i]);
            }
        }
        for(int i=0;i<nums.size();i++){
            nums[i] = result[i];
        }
    }
};