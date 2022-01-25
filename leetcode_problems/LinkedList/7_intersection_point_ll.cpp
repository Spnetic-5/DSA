// Brute Force Approach TC: O(N+M) SC: Q(N+M)
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
     if(headA == NULL || headB == NULL) {
        return NULL;
    }
        
    ListNode* tempA = headA;
        
    while(tempA != NULL){
        ListNode* tempB = headB;
        while(tempB != NULL){
            if(tempA == tempB){
                return tempA;
            }
            tempB = tempB->next;
        }
           
        tempA = tempA->next;
    }
    return NULL;
}



// 1st Optimum Approach TC: O(2M) or O(2N) SC: O(1)
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
         
if(headA == NULL || headB == NULL) {
    return NULL;
}
ListNode* tempA = headA;
ListNode* tempB = headB;
int l1 = 0, l2 = 0;
 while(tempA != NULL){
     l1+=1;
     tempA = tempA->next;
 }
 while(tempB != NULL){
     l2+=1;
     tempB = tempB->next;
 }
int diff = abs(l1-l2);
tempA = headA;
tempB = headB;
if (l1 < l2){
    for(int i =0; i<diff; i++){
        tempB = tempB->next;
    }
    while (tempA!=tempB){
        tempA = tempA->next;
        tempB = tempB->next;
    }
}
else if (l2 < l1){
    for(int i =0; i<diff; i++){
        tempA = tempA->next;
    }
    while (tempA!=tempB){
        tempA = tempA->next;
        tempB = tempB->next;
    }
}
else{
    while (tempA!=tempB){
        tempA = tempA->next;
        tempB = tempB->next;
    }
}
        
return tempA;
}
        


// 2nd Optimum Approach TC: O(2M) or O(2N) SC: O(1)
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
     if(headA == NULL || headB == NULL) {
        return NULL;
    }
        
    ListNode* tempA = headA;
    ListNode* tempB = headB;
        
    while(tempA != tempB){
            
        if(tempA == NULL){
        tempA = headB;
        }
        else{
        tempA = tempA->next;
        }
        if(tempB == NULL){
        tempB = headA;
        }
        else{
        tempB = tempB->next;
        }
    }  
return tempA;
}