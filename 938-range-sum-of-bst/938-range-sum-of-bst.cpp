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
    
    vector <int> a;
    
    void inorder(TreeNode* root){
        if(root == NULL){
            return;
        }
        
        inorder(root->left);
        a.push_back(root->val);
        inorder(root->right);
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        inorder(root);
        
        int sum = 0;
        
        for(int i=0;i<a.size();i++){
            if(a[i] >= low && a[i] <= high){
                sum = sum + a[i];
            }
        }
        
        return sum;
    }
};