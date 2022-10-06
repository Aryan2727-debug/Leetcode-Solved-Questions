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
    
    TreeNode* buildBST(int l , int r){
        if(l > r){
            return NULL;
        }
        
        int mid = (l+r)/2;
        
        TreeNode* root = new TreeNode(a[mid]);
        root->left = buildBST(l , mid-1);
        root->right = buildBST(mid+1 , r);
        
        return root;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        
        return buildBST(0 , a.size()-1);
    }
};