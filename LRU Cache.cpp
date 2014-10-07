// put LRU at the head, remove the first element when the cache is full. move the used element to the end. 
// hashmap + doubly linked list
struct Node{ 
    Node *prev;
    Node *next;
    int key;
    int val;
    Node(int k, int v) : key(k), val(v), prev(NULL), next(NULL) {} 
};

class LRUCache{
private:
    int capacity;    
    map<int, Node*> m;
    Node *head;
    Node *tail;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(m.find(key) == m.end()) {
            return -1;
        }
        
        // update cache
        Node *current = m[key];
        current->prev->next = current->next;
        current->next->prev = current->prev;
        MoveToTail(current);
        
        return m[key]->val;
    }
    
    void set(int key, int value) {
        // if key exists, update value
        if(get(key) != -1){ // updated linked list in "get"
            m[key]->val = value;
            return;
        }
        // discard LRU is full, discard the first element
        if(m.size() == capacity){
            Node *first = head->next;
            head->next = head->next->next;
            head->next->prev = head;
            m.erase(first->key); // bug happened here
        }    
        // insert new 
        Node *newNode = new Node(key, value);
        m[key] = newNode;
        MoveToTail(newNode);
    }
    
    void MoveToTail(Node *curNode){
        tail->prev->next = curNode;
        curNode->prev = tail->prev;
        tail->prev = curNode;
        curNode->next = tail;
    }
};