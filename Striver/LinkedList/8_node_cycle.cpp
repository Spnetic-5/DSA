// Detect a Cycle in Linked List TC: O(N) SC: Q(1)

bool hasCycle(ListNode *head) {
    if(head == NULL || head->next == NULL){
        return false;
    }
        
    ListNode* slow = head;
    ListNode* fast = head;
        
    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
         if(slow==fast){
            return true;
        }
    }
    return false;
}