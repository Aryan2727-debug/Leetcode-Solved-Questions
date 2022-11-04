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
class Solution {
public:
    
    //finding middle node of linked list
    
    ListNode* findMiddle(ListNode* head){
        ListNode* fast = head->next;
        ListNode* slow = head;
        
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    //merging 2 sorted linked lists
    
    ListNode* merge(ListNode* l1 , ListNode* l2){
        if(l1 == NULL){
            return l2;
        }
        
        if(l2 == NULL){
            return l1;
        }
        
        if(l1->val < l2->val){
            l1->next = merge(l1->next , l2);
            return l1;
        }else{
            l2->next = merge(l1 , l2->next);
            return l2;
        }
    }
    
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        ListNode* mid = findMiddle(head);
        
        //dividing the linked list into 2 halves
        
        ListNode* leftHalf = head;
        ListNode* rightHalf = mid->next;
        
        mid->next = NULL;
        
        //recursive calls to left and right halves
        
        leftHalf = sortList(leftHalf);
        rightHalf = sortList(rightHalf);
        
        //merging the 2 halves into a single linked list
        
        ListNode* result = merge(leftHalf , rightHalf);
        
        return result;
    }
};