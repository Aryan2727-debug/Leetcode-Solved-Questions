class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        
        //calculating appropriate size of k to avoid index out of bounds
        k = k%n;
        
        
        reverse(nums.begin() , nums.end());           //reversing entire array
        reverse(nums.begin() , nums.begin() + k);     //reversing upto k
        reverse(nums.begin() + k , nums.end());       //reversing to maintain original order
    }
};