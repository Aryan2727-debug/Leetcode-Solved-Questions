class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n=nums.size();
        long long total=(n*(n-1)/2),good=0;
        unordered_map<int,int>ump;
        for(int i=0;i<n;i++)
        {
            if(ump[i-nums[i]]>=1)
                good+=ump[i-nums[i]];
            ump[i-nums[i]]++;
        }
        return total-good;
    }
};