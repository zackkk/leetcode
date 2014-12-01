// put LRU at the head, remove the first element when the cache is full. move the used element to the end. 
// hashmap + doubly linked list
struct node{
    int key; // map erase by key
    int val;
    node *prev;
    node *next;
    node(int k, int v) : key(k), val(v), prev(NULL), next(NULL) {}
};

// tried once then AC, :)
class LRUCache{
private:
    map<int, node*> m;
    map<int, node*>::iterator it;
    int size;
    int capacity;
    node *head;
    node *tail;
    
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        size = 0;
        head = new node(-1, -1);
        tail = new node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    void moveToHead(node *n){
        node *tmp = head->next;
        head->next = n;
        n->prev = head;
        n->next = tmp;
        tmp->prev = n;
    }
    
    void extractNode(node *n){
        n->prev->next = n->next;
        n->next->prev = n->prev;
        n->prev = NULL;
        n->next = NULL;
    }
    
    int get(int key) {
        it = m.find(key);
        if(it == m.end())
            return -1;
        else{
            extractNode(it->second);
            moveToHead(it->second);
            return it->second->val;
        }
    }
    
    void set(int key, int value) {
        it = m.find(key);
        if(it == m.end()){
            node *tmp = new node(key, value);
            moveToHead(tmp);
            m[key] = tmp;
            size++;
            if(size > capacity){
                node *toDel = tail->prev;
                extractNode(toDel);
                m.erase(toDel->key);
                delete(toDel);
                size--;
            }
        }
        else{
            extractNode(it->second);
            moveToHead(it->second);
            it->second->val = value;
        }
    }
};