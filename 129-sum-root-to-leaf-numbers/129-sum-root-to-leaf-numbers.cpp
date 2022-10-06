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
    
    int ans = 0;             //the final answer variable
    
    void dfs(TreeNode* root , int val){    //val = variable used to keep track of current number  
        if(root == NULL){
            return;
        }
        
        val = val * 10;           //used to change the place of unit's digit
        
        val = val + root->val;    //adding the value of current root to val
        
        if(root->left == NULL && root->right == NULL){
            ans = ans + val;        //updating the value of final ans variable
            return;
        }
        
        dfs(root->left , val);
        dfs(root->right , val);
        
    }
    
    int sumNumbers(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        
        dfs(root , ans);
        
        return ans;
    }
};