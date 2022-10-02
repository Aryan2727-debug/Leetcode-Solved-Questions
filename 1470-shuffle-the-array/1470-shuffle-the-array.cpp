class Solution {
public:
vector<int> shuffle(vector<int> & nums, int n) {

    //initialize a new vector
    vector<int> res;
    
    //loop over the half array elements
    for(int i=0;i<n;i++){
        //append the current elements
        res.push_back(nums[i]);
        //then, append the current one in the second half array
        res.push_back(nums[i+n]);
    }
    
    //return the new array elements
    return res;
}
};