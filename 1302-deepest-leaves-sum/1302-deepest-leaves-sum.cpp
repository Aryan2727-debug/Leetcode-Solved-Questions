/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> v[10001];
    int mxLevel = 0, levelNo = 0;
    
    void dfs(TreeNode* root, int level = 0) {
        if(!root) {
            return;
        }
        
        v[level].push_back(root->val);
        
        mxLevel = max(mxLevel, level);
        
        dfs(root->left,  level+1);
        dfs(root->right, level+1);
    }
    
    int deepestLeavesSum(TreeNode* root) {            
        dfs(root);
                
        int sum = 0;
        for(int x : v[mxLevel]) sum += x;
        
        return sum;
    }
};