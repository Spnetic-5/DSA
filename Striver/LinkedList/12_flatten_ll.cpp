
/*  Function which returns the  root of 
    the flattened linked list. */
Node* mergeLL(Node* a, Node* b){
    Node* temp = new Node(0);
    Node*res = temp;
    
    while(a!=NULL && b!=NULL){
        if(a->data < b->data){
            temp->bottom = a;
            temp = temp->bottom;
            a = a->bottom;
        }
        else{
            temp->bottom = b;
            temp = temp->bottom;
            b = b->bottom;
        }
    }
    if(a) temp->bottom = a;
    else temp->bottom = b;
        
    return res->bottom;
}

Node *flatten(Node *root)
{
   // Your code here
  if(root == NULL || root->next == NULL){
      return root;
  }
  
//   recur to right
  root->next = flatten(root->next);
// merge
  root = mergeLL(root, root->next);
   
  return root;
}