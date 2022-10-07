struct node {
    int val;
    int state;
    node *next;
    node(int val, int state) {
        this -> val = val;
        this -> state = state;
        next = NULL;
    }
};

class MyCalendarThree {
public:
    struct node *head = new node(-1, 0);
    
    MyCalendarThree() {}
    
    int book(int start, int end) {
        insert(start, 1);
        insert(end, -1);
        int ans = 1, cnt = 0;
        
        auto cur = head -> next;
        while (cur) {
            cnt += cur -> state;
            ans = max(ans, cnt);
            cur = cur -> next;
        }
        return ans;
    }
    
    void insert(int val, int state) {
        auto cur = head;
        struct node *Node = new node(val, state);
        while (cur -> next) {
			// if node with greater value exists ahead of it
            if (cur -> next -> val > val) {
                Node -> next = cur -> next;
                cur -> next = Node;
                return;
            }
			
			// if node with equal value exists ahead of it
            if (cur -> next -> val == val) {
                cur -> next -> state += state;
                return;
            }
            cur = cur -> next;
        }
		
		// when current val is greatest among all the existing nodes
        cur -> next = Node;
    }
};
/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */