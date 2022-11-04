/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    
    //function to find the length of the linked list
    
    int length(ListNode* head){
        int l = 0;
        ListNode* temp = head;
        
        while(temp != NULL){
            temp = temp->next;
            l++;
        }
        return l;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1 = length(headA);       //length of 1st ll
        int l2 = length(headB);       //length of 2nd ll
        
        int diff = 0;
        ListNode* ptr1;      //points to ll with larger length
        ListNode* ptr2;      //points to ll with smaller length
        
        if(l1 > l2){
            diff = l1-l2;
            ptr1 = headA;
            ptr2 = headB;
        }else{
            diff = l2-l1;
            ptr1 = headB;
            ptr2 = headA;
        }
        
        while(diff){
            ptr1 = ptr1->next;
            
            //if no intersection node is found
            
            if(ptr1 == NULL){
                return NULL;
            }
            
            diff--;
        }
        
        while(ptr1 != NULL && ptr2 != NULL){
            
            //if intersection node is found, return it
            
            if(ptr1 == ptr2){
                return ptr1;
            }
            
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        
        return NULL;
    }
};