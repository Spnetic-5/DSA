void deleteNode(ListNode* node) {
        
    if(node->next == NULL){
        node = NULL;
    }
        
    node-> val = node->next->val;
    node->next = node->next->next;
}