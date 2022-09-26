class Solution {
public:
    
    void remove(std::vector<int> &v)
{
    auto end = v.end();
    for (auto it = v.begin(); it != end; ++it) {
        end = std::remove(it + 1, end, *it);
    }
 
    v.erase(end, v.end());
}
    
    int thirdMax(vector<int>& nums) {
        remove(nums);
        sort(nums.begin() , nums.end());
        if(nums.size()<3){
            return *max_element(nums.begin() , nums.end());
        }else{
            for(int i=0;i<=nums.size()-3;i++){
                if(i == nums.size()-3){
                    return nums[i];
                }
            }
        }
        return -1;
    }
};