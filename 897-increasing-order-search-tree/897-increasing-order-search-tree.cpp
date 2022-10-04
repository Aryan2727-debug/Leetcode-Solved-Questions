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
    
    TreeNode* increasingBST(TreeNode* root) {
        inorder(root);
        sort(a.begin() , a.end());
        
        TreeNode* Root  = new TreeNode(a[0]);
        Root->left = Root->right = NULL;
        TreeNode *t = Root ;
        
       for(int i = 1 ; i<a.size();i++)
    {
       TreeNode* temp = new TreeNode(a[i]);
       t->right = temp ;
       t = t->right;
     }
        
       return Root;
        
    }
};