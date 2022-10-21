/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    
    //function to find the middle element in the Linked List
    
    ListNode* findMiddle(ListNode* head , ListNode* end){
        if(head == end){
            return NULL;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != end && fast->next != end){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    //function to create the BST
    
    TreeNode* buildBST(ListNode* start , ListNode* end){
        if(start == end){
            return NULL;
        }
        
        ListNode* mid = findMiddle(start , end);
        
        TreeNode* root = new TreeNode(mid->val);
        root->left = buildBST(start , mid);
        root->right = buildBST(mid->next , end);
        
        return root;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL){
            return NULL;
        }
        
        return buildBST(head , NULL);
    }
};