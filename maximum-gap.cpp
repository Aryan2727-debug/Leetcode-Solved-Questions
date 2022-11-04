class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2){
            return 0;
        }
        
        sort(nums.begin() , nums.end());
        
        int difference = 0;
        
        for(int i=1;i<nums.size();i++){
            difference = max(difference , abs(nums[i]-nums[i-1]));
        }
        return difference;
    }
};