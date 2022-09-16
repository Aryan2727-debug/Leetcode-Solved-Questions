class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
       int result[nums.size()];
        for(int i=0;i<nums.size();i++){
            result[i] = nums[i]*nums[i];
        }
        vector <int> a;
        for(int i=0;i<nums.size();i++){
            a.push_back(result[i]);
        }
        sort(a.begin() , a.end());
        return a;
    }
};