class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map <int,int> mp;

        int n = nums.size();

        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }

        int count = n;

        for(int i=0;i<n;i++){
            int x = nums[i];

            if(mp[x] && mp[x+1] && mp[x+2]){
               mp[x]--;
               mp[x+1]--;
               mp[x+2]--;
               x += 3;
               count -= 3;

               while(mp[x] > 0 && mp[x] > mp[x-1]){
                   count--;
                   mp[x]--;
                   x++;
               }
            }
        }
        return count == 0;
    }
};