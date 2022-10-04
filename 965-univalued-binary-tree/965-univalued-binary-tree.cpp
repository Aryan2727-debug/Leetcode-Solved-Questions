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
    
    set<int> convertToSet(vector<int> v)
{
    // Declaring the set
    set<int> s;
 
    // Traverse the Vector
    for (int x : v) {
 
        // Insert each element
        // into the Set
        s.insert(x);
    }
 
    // Return the resultant Set
    return s;
}

    
    void inorder(TreeNode* root){
        if(root == NULL){
            return;
        }
        
        inorder(root->left);
        a.push_back(root->val);
        inorder(root->right);
    }
    
    bool isUnivalTree(TreeNode* root) {
        inorder(root);
        
        set <int> s = convertToSet(a);
        
        if(s.size() == 1){
            return true;
        }
        
        return false;
    }
};