// Using Dummy nodes Approach TC: O(N) SC: O(N) 
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode dummy;
    ListNode* tail = &dummy;
    dummy.next = NULL;
        
    while(1){
            
        if(l1==NULL){
            tail->next = l2;
            break;
        }
        if(l2==NULL){
            tail->next = l1;
            break;
        }
            
        if (l1->val <= l2->val){
            MoveNode(&(tail->next), &l1);
        }
            
        else{
            MoveNode(&(tail->next), &l2);
        }
            
        tail = tail->next;
            
    }
        
    return(dummy.next);
}
    
void MoveNode(ListNode** destRef, ListNode** sourceRef)
{
    /* the front source node */
    ListNode* newNode = *sourceRef;   


    /* Advance the source pointer */
    *sourceRef = newNode->next;

    /* Link the old dest off the new node */
    newNode->next = *destRef;

    /* Move dest to point to the new node */
    *destRef = newNode;
}
 
// ------------------------------------------------------------------

// Optimum Recursion Appproach - TC: O(N+M) SC: O(1)

ListNode* SortedMerge(ListNode* a, ListNode* b)
{
    ListNode* result = NULL;
     
    /* Base cases */
    if (a == NULL)
        return(b);
    else if (b == NULL)
        return(a);
     
    /* Pick either a or b, and recur */
    if (a->data <= b->data)
    {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else
    {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return(result);
}



// Optimum Inplace Appproach - TC: O(N+M) SC: O(1)

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
                
    if(l1==NULL){
        return l2;
    }
    if(l2==NULL){
        return l1;
    }

    if (l1->val > l2->val){
        std::swap(l1,l2);
    }
        
    ListNode* res = l1;

    while(l1!=NULL && l2!=NULL){
        ListNode* tmp=NULL;
        while(l1!=NULL && l1->val <= l2->val){
            tmp = l1;
            l1 = l1->next;
        }
        tmp->next = l2;
        std::swap(l1, l2);
    }

        
    return res;
}


