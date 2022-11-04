class Solution {
public:
    int findMin(vector<int>& nums) {
        
        if(nums.size() == 0){            //edge case
            return 0;
        }
        
        int minimum = *min_element(nums.begin() , nums.end());       //finding minimum element
        
        return minimum;
    }
};