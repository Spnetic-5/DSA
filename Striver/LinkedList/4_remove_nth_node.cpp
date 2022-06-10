

// Optimized Solution TC: O(n) SC: Q(1) 
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* start = new ListNode();
    start->next = head;
    ListNode* fast = start;
    ListNode* slow = start;
        
    for(int i=0; i <= n; i++){
        fast = fast->next;
    }
        
    while(fast != NULL){
        fast = fast->next;
        slow= slow->next;
    }
        
    slow->next = slow->next->next;
    return start->next;
}