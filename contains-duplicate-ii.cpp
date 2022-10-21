class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map <int,int> mp;
        int n = nums.size();
        
        for(int i=0;i<n;i++){
            if(mp.count(nums[i])){              //if we have already seen a value in the array
                if(abs(i-mp[nums[i]]) <= k){    //check for applying condition
                    return true;
                }
            }
            mp[nums[i]] = i;                    //otherwise update the value
        }
        return false;
    }
};