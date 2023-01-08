class Solution {
public:

    int rev(int n){
        int x = n;
        int reverse = 0;

        while(n > 0){
            reverse = reverse * 10 + n%10;
            n = n / 10;
        }

        return reverse;
    }

    int countNicePairs(vector<int>& nums) {

        unordered_map<int,int> mp;     

        int count = 0;

        for(int i=0;i<nums.size();i++)
        {
            int tmp=nums[i] - rev(nums[i]);        
            mp[tmp]++;
            count = (count + mp[tmp] - 1) % 1000000007;      
        }
        return count % 1000000007;
    }
};