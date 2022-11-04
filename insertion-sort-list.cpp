class Solution {
public:
ListNode* insertionSortList(ListNode* head) {

    if(head == nullptr) return nullptr;
    
    int temp = 0;
    for(ListNode* curr = head; curr != nullptr; curr = curr->next){
        for(ListNode* prev = head; prev != curr; prev = prev->next){
            if(curr->val < prev->val){
                temp = curr->val;
                curr->val = prev->val;
                prev->val = temp;
            }
        }
    }
    return head;
}
};