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
    
    bool findTarget(TreeNode* root, int k) {
        
        inorder(root);
        
        sort(a.begin() , a.end());
        
        int low = 0;
        int high = a.size()-1;
        
        while(low<high){
            if(a[low] + a[high] == k){
                return true;
            }
            else if(a[low] + a[high] > k){
                high--;
            }
            else{
                low++;
            }
        }
        return false;
        
    }
};