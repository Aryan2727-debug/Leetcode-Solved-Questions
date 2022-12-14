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
    void inorderTraversal(TreeNode* root, unordered_map<int, int> &mp){
        if(root == NULL) return;                                                   // inorder traversal
        
        inorderTraversal(root->left, mp);
        mp[root->val]++;
        inorderTraversal(root->right, mp);
    }
	
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> mp;
        vector<int> ans;
        inorderTraversal(root, mp);
        int maxValue =  INT_MIN;
		
        for(auto i: mp){                                         // for loop to find maxValue
            if(maxValue < i.second){
                maxValue = i.second;
            }
        }
		
        for(auto i: mp){                                       // for loop to find element value and push to ans
            if(i.second == maxValue){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};