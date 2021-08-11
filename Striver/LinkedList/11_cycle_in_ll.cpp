
// Brute Hash Table Approach 
// TC: O(N) SC: O(N) 

ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> s;
         while (head != NULL) {
        if (s.find(head) != s.end())
            return head;
 
        s.insert(head);
        head = head->next;
    }
    return head;
    }

// Optimized Approach using slow and fast pointers
// TC: O(N) SC: O(1)
ListNode *detectCycle(ListNode *head) {
       if(head == NULL || head->next == NULL){
        return NULL;
    }
        
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* entry = head;
        
    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
         if(slow==fast){
             while(slow!=entry){
                 slow = slow->next;
                 entry = entry->next;
             }
            return entry;
        }
    }
    return NULL;
    }