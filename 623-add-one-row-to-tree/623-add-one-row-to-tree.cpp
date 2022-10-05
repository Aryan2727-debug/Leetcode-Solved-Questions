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
    
    TreeNode* helper(TreeNode* root , int val , int depth){
        if(root == NULL){
            return NULL;
        }
        
        if(depth == 1){
            TreeNode* temp = new TreeNode(val);
            temp->left = root;
            return temp;
        }
        
        if(depth == 2){
            TreeNode* node1 = new TreeNode(val);
            TreeNode* node2 = new TreeNode(val);
            
            node1->left = root->left;
            node1->right = NULL;
            
            node2->right = root->right;
            node2->left = NULL;
            
            root->left = node1;
            root->right = node2;
            
            return root;
        }
        
        helper(root->left , val , depth-1);
        helper(root->right , val , depth-1);
        return root;
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        return helper(root , val , depth);
    }
};