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
    
    //function for inorder traversal on the tree
    
    void inorder(TreeNode* root){
        if(root == NULL){
            return;
        }
        
        inorder(root->left);
        a.push_back(root->val);
        inorder(root->right);
    }
    
    //function to change the value of the nodes
    
    void changeNodeVal(TreeNode* root , vector<int> :: iterator &it){
        if(root == NULL){
            return;
        }
        
        changeNodeVal(root->left , it);
        
        root->val = *it;
        it++;
        
        changeNodeVal(root->right , it);
    }
    
    void recoverTree(TreeNode* root) {
        
        if(root == NULL){
            return;
        }
        
        inorder(root);
        
        sort(a.begin() , a.end());
        
        vector<int> :: iterator it = a.begin();
        
        changeNodeVal(root , it);
    }
};