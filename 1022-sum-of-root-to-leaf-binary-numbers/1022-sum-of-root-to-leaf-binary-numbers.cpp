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

    int sumRootToLeaf(TreeNode* root, int sum)
    {
        //if root does not exist, return 0
        
        if(root == NULL){
            return 0;
        }
        
        //update the sum value in form of Binary Number
        
        sum=(2*sum) + root->val;
        
        //when we approach the leaf, return the sum;
        
        if(root->left == NULL && root->right == NULL){ 
            return sum;
        }
        
        //recursively call the functions to add left and right children
        
        return sumRootToLeaf(root->left, sum) + sumRootToLeaf(root->right, sum);
    }
    
    public:
    int sumRootToLeaf(TreeNode* root) {
        return sumRootToLeaf(root,0);
    }
};