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
    
    TreeNode* buildBST(vector<int>& a , int l , int r){
        if(l > r){
            return NULL;
        }
        
        sort(a.begin() , a.end());
        
        int mid = (l+r)/2;
        
        TreeNode* root = new TreeNode(a[mid]);
        root->left = buildBST(a , l , mid-1);
        root->right = buildBST(a , mid+1 , r);
        
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0){
            return NULL;
        }
        
        return buildBST(nums , 0 , nums.size()-1);
    }
};