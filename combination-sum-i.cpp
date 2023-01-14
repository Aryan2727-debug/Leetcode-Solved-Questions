class Solution {
public:

    vector<vector<int>> ans;

    void solve(int index, vector<int> &arr, vector<int> &ds, int target){
        if(target == 0){
            ans.push_back(ds);
            return;
        }

        if(target < 0){
            return;
        }

        if(index == arr.size()){
            return;
        }

        solve(index+1, arr, ds, target);                  //PICK
        ds.push_back(arr[index]);

        solve(index, arr, ds, target-arr[index]);       //NOT PICK
        ds.pop_back();
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        ans.clear();

        vector<int> ds;

        solve(0, candidates, ds, target);

        return ans;
    }
};