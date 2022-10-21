class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProduct = nums[0];
        int minProduct = nums[0];
        int result = nums[0];
        
        for(int i=1;i<nums.size();i++){
            if(nums[i] < 0){
                int temp = minProduct;
                minProduct = maxProduct;
                maxProduct = temp;
            }
            
            maxProduct = max(maxProduct*nums[i] , nums[i]);
            minProduct = min(minProduct*nums[i] , nums[i]);
            
            result = max(result , maxProduct);
        }
        return result;
    }
};