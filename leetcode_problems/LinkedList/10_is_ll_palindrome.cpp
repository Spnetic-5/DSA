// TC: O(n/2) + O(n/2) + O(n/2)
// SC: Q(1) 

bool isPalindrome(ListNode* head) {
    if(head==NULL || head->next==NULL){
        return true;
    }
        
    ListNode* slow = head;
    ListNode* fast = head;
        
    while(fast->next  != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
        
    slow->next = reverseList(slow->next);
    slow = slow->next;
        
    while(slow!=NULL){
        if(head->val != slow->val){
            return false;
        }
        head = head->next;
        slow = slow->next;
    }
    return true;
}
    
ListNode* reverseList(ListNode* head) {
    ListNode* newHead = NULL;
    while(head != NULL){
        ListNode* next = head->next;
        head->next = newHead;
        newHead = head;
        head = next;
    }
    return newHead;
}