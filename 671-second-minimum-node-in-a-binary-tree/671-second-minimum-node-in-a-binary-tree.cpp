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
    void preorder(TreeNode* root,set<int>&v)
    {
        if(!root) return;
        v.insert(root->val);
        preorder(root->left,v);
        preorder(root->right,v);
     }
    int findSecondMinimumValue(TreeNode* root) {
        set<int>v;
        preorder(root,v);
        int i=0;
        int ans=-1;
        for(auto it:v){
            if(i==1){
                ans=it;
            }
            i++;
        }
        return ans;
    }
};