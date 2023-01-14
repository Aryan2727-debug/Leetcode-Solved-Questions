class Solution {
public:

    vector<vector<int>> result;

    void solve(int index, vector<int>& arr, vector<int>& ds, int target){
        if(target == 0){
            result.push_back(ds);
            return;
        }

        for(int i=index;i<arr.size();i++){
            if(i > index && arr[i] == arr[i-1]){
                continue;
            }
            if(arr[i] > target){
                break;
            }
            ds.push_back(arr[i]);
            solve(i+1, arr, ds, target-arr[i]);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> ds;

        sort(candidates.begin() , candidates.end());

        solve(0, candidates, ds, target);

        return result;
    }
};