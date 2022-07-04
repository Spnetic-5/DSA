class LRUCache {
    public:
    class node  {
        public: 
        int key;
        int val;
        node* prev;
        node* next;
        node(int _key, int _val){
            key = _key;
            val = _val;
        }
    };

    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);

    int cap;
    unordered_map<int, node*> mpp;

    LRUCache(int capacity){
        cap = capacity;
        head->next = tail;
        tail->next = head;
    }

    void addnode(node* newnode){
        int next = head->next;
        
        head->next = newnode;
        next->prev = newnode;

        newnode->next = next;
        newnode->prev = head;
    }

    void deletenode(node* delnode){
        int prevnode= delnode->prev;
        int nextnode= delnode->next;
        
        prevnode->next = nextnode;
        nextnode->prev = prevnode;
    }

    void get(key_){
        if(mpp.find(key_) != mpp.end()){
            node* resnode = mpp[key_];
            int res = resnode->val;
            mpp.erase(key_);
            deletenode(resnode);
            addnode(resnode);
            mpp[key_] = head->next;
            return res;
        }
        return -1;
    }

    void put(int key_, int value){
        if(mpp.find(key_) != mpp.end()){
            node* oldnode = mpp[key_];
            mpp.erase(key_);
            deletenode(oldnode);
        }
        if(mpp.size() == cap){
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(key_, value));
        m[key_] = head->next;
    }

}