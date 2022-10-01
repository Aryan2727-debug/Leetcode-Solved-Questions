class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector <int> v;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                int a = (nums[i]-1)*(nums[j]-1);
                v.push_back(a);
            }
        }
        return *max_element(v.begin() , v.end());
    }
};