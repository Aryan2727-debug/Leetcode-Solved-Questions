class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> v(nums);

        sort(nums.begin() , nums.end());

        int start = v.size();
        int end = 0;

        for(int i=0;i<v.size();i++){
            if(v[i] != nums[i]){
                start = min(start , i);
                end = max(end , i);
            }
        }

        return (end - start >= 0) ? (end - start + 1) : 0;
    }
};