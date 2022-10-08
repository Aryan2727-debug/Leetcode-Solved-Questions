class Solution {
void solution(vector<int>& arr, vector<vector<int>>& ans){
    //sorting is necessary for implementing the two poiinter algorithm.
    sort(arr.begin(), arr.end());
    set<vector<int>> hash;  //hashmap to prevent duplication of triplets.
    int n = arr.size();
    //considers each element of the given array to be 'a'
    for(int i=0;i<n-2;i++){
        int target = -arr[i];
        //two pointer algorithm
        int s = i+1, e=n-1;
        while(s<e){
            int sum = arr[s]+arr[e];
            if(sum==target){
                hash.insert({-target, arr[s], arr[e]});
                s++;
                e--;
            }
            if(sum > target) e--;
            if(sum < target) s++;
        }
    }
    
    for(auto it : hash){
        ans.push_back(it);
    }
}
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        solution(nums, ans);
        return ans;
    }
};