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
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector <int> result;
        
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(nums1[i] == nums2[j]){
                    result.push_back(nums1[i]);
                }
            }
        }
        remove(result);
        return result;
    }
};