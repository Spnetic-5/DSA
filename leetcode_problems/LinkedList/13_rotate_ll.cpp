//  Brute Approach, doesn't pass edge cases
// TC: O(n x k) SC: O(1)
 ListNode* rotateRight(ListNode* head, int k) {
        
        if (k == 0 || head == NULL)
        return head;
        
     
        ListNode* dummy = head;
        
        int count = 0;
        while (count < k && dummy != NULL) {
            dummy = dummy->next;
            count++;
        }
        if (dummy == NULL){
          dummy = head->next;  
        } 
        
        ListNode* kthNode = dummy;
        
        while (dummy->next != NULL){
        dummy = dummy->next;
        }
        
        dummy->next = head;
        head = kthNode->next;
        kthNode->next = NULL;
        
        return head;
    }

// Optimum Approach, if k is multiple of lenght of list, then k = k%len 
// TC: O(n) SC: O(1)
ListNode* rotateRight(ListNode* head, int k) {
        
        // edge cases
        if(!head || !head->next || k==0) return head;
        
        // find len
        ListNode* dummy = head;
        int len = 1;
        while(dummy->next && ++len){
            dummy = dummy->next;
        }
        // make LL circular
        dummy -> next = head;
        
        // go to node 
        k = k % len;
        k = len - k;
        while(k--){
            dummy = dummy->next;
        }
        
        head = dummy->next;
        dummy->next = NULL;
       
        return head;
    }