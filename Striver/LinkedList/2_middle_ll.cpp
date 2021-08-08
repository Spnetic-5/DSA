// Simple Approach
ListNode* middleNode(ListNode* head) {
    int len = 0;
    ListNode *crawl = head;
    ListNode *newHead = head;
    while(crawl != NULL){
        len++;
        crawl = crawl->next;            
    }
    int mid = (len/2) + 1;
    while(--mid>0){
        cout<<mid<<" ";
        newHead = newHead->next;
    }
    return newHead;
}

// Optimized Approach 2 pointer(fast & slow)
ListNode* middleNode(ListNode* head) {
    ListNode* slow = head; 
    ListNode* fast = head;
    while(fast!= NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}