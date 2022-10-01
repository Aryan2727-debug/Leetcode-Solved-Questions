class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        vector <string> v;
        for(int i=0;i<nums.size();i++){
            string s = to_string(nums[i]);
            v.push_back(s);
        }
        
        for(int i=0;i<v.size();i++){
            if(v[i].length()%2 == 0){
                count++;
            }
        }
        return count;
    }
};