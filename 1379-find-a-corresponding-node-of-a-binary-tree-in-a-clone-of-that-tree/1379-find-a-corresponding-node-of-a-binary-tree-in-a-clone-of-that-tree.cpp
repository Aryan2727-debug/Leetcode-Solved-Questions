/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    
    TreeNode* getTargetCopy(TreeNode* root1, TreeNode* root2, TreeNode* target) {
           if(!root2)
            return NULL;
        
        if(root1 == target)
            return root2;
        
     
        
        TreeNode* l = getTargetCopy(root1->left,root2->left,target);
        TreeNode* r = getTargetCopy(root1->right,root2->right,target);
        
        if(l != NULL)
            return l;
        
        return r;

    }
};
