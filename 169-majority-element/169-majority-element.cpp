class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> _map;
        for (int v : nums) if (++_map[v] > nums.size() / 2) return v;
        return -1;
    }
    
};