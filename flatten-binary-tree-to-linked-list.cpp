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
    void flatten(TreeNode* root) {
        
        //base case
        
        if(root == NULL){
            return;
        }
        
        //storing the left and right nodes in temporary variables
        
        TreeNode* tempLeft = root->left;
        TreeNode* tempRight = root->right;
        
        //making the left node NULL acc. to the question
        
        root->left = NULL;
        
        //recursive calls to left and right subtrees
        
        flatten(tempLeft);
        flatten(tempRight);
        
        //making the right node as left
        
        root->right = tempLeft;
        
        //attaching the right node at appropriate places
        
        TreeNode* current = root;
        
        while(current->right != NULL){
            current = current->right;
        }
        
        current->right = tempRight;
    }
};