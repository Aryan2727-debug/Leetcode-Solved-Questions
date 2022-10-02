class Solution {
public:
int numRollsToTarget(int n, int k, int target)
{
if (target > n * k) return 0;

    const int mod = 1e9+7;
    int prevStart = max(1, target - (n-1)*k);
    int prevEnd = min(k, target - (n-1));
    vector<int> dp(prevEnd-prevStart+1, 1);        
    
    for (int dice = 1; dice < n-1; ++dice)
    {
        int start = max(dice + 1, target - k*(n-1-dice));
        int end = min(k*(dice+1), target - (n-1-dice));
        
        vector<int> dp_t(end-start+1, 0);
        for (int i = 0; i < min(prevEnd-prevStart+1, start - prevStart); ++i)
        {
            dp_t[0] = dp_t[0] - mod + dp[i] > 0 ? dp_t[0] - mod + dp[i] : dp_t[0] + dp[i];
        }
        
        for (int i = 1; i < dp_t.size(); ++i)
        {
            const int currSum = start + i;
            if (currSum-k <= prevStart)
            {
                dp_t[i] = dp_t[i-1] - mod + dp[currSum-prevStart-1] > 0 ? dp_t[i-1] - mod + dp[currSum-prevStart-1] : dp_t[i-1] + dp[currSum-prevStart-1];
            }
            else
            {
                dp_t[i] = dp_t[i-1] - dp[currSum - k - prevStart - 1] < 0 ? dp_t[i-1] - dp[currSum - k - prevStart - 1] + mod : dp_t[i-1] - dp[currSum - k - prevStart - 1];
                if (currSum-prevStart-1 < dp.size()) dp_t[i] = dp_t[i] - mod + dp[currSum-prevStart-1] > 0 ? dp_t[i] - mod + dp[currSum-prevStart-1] : dp_t[i] + dp[currSum-prevStart-1];
            }
        }
        
        dp = dp_t;
        prevStart = start;
        prevEnd = end;
    }
    int ans = 0;
    for_each(dp.begin(), dp.end(), [&ans, &mod](const auto &dp_i){ans = ans - mod + dp_i > 0 ? ans - mod + dp_i : ans + dp_i;});
    return ans;
}
};