class Solution {
public:

    vector<vector<int>> result;

    int sum(vector<int> &combinations){
        int ans = 0;
        for(int i=0;i<combinations.size();i++){
            ans += combinations[i];
        }
        return ans;
    }

    void helper(int k, int n, vector<int> &combination, int num){
        if(k == 0){
            if(sum(combination) == n){
                result.push_back(combination);
            }
            return;
        }

        if(num > 9){
            return;
        }

        combination.push_back(num);
        helper(k-1, n, combination, num+1);
        combination.pop_back();
        helper(k, n, combination, num+1);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> combination;
        helper(k, n, combination, 1);
        return result;
    }
};