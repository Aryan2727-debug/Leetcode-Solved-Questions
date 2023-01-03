class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {

        int ans = -1;
        int lastIndex = -1;

        vector<int> dp(nums.size(),1);
        vector<int> trace(nums.size(),-1);

        sort(nums.begin() , nums.end());

        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if((nums[i]%nums[j] == 0) && (dp[j] >= dp[i])){
                    dp[i] = dp[j] + 1;
                    trace[i] = j;
                }
            }
            if(dp[i] > ans){
                    ans = dp[i];
                    lastIndex = i;
            }
        }

        vector<int> path;

        while(lastIndex != -1){
            path.push_back(nums[lastIndex]);
            lastIndex = trace[lastIndex];
        }

        reverse(path.begin() , path.end());
        return path;
    }
};