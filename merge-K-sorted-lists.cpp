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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        
        if(n == 0){
            return NULL;
        }
        
        //initializing a priority queue
        
        priority_queue <int,vector<int>,greater<int>> pq;
        
        //pushing all nodes of all lists into the priority queue
        
        for(int i=0;i<n;i++){
            ListNode* temp = lists[i];
            
            while(temp != NULL){
                pq.push(temp->val);
                temp = temp->next;
            }
        }
        
        //in priority queue, always the smallest element is popped out first
        //we will pop from the priority queue and insert into the newly created list
        
        ListNode* start = new ListNode(0);
        ListNode* head = start;
        
        while(!pq.empty()){
            head->next = new ListNode(pq.top());
            pq.pop();
            head = head->next;
        }
        return start->next;
    }
};