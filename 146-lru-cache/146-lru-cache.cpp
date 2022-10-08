struct Node {
    int value;
    int key;
    Node *prev;
    Node *next;
    Node() : key(0), value(0), prev(nullptr), next(nullptr) {}
    Node(int _key, int _value) : key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
    unordered_map<int, Node*> hashMap; // check whether the key is in cache
    Node * head; // least recently used
    Node * tail; // most recently used
    int total;
    int cur = 0;
    
public:
    LRUCache(int capacity) {
        total = capacity;
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (hashMap.find(key) == hashMap.end()) {
            return -1;
        }
        Node * node = hashMap[key];
        int val = node->value;
        moveToTail(node);
        return val;
    }
    
    void put(int key, int value) {
        if (hashMap.find(key) != hashMap.end()){ // contains
            Node * node = hashMap[key];
            node->value = value;
            moveToTail(node);
        }
        else {
            Node * node = new Node(key, value);
            addToTail(node);
            ++cur;
            hashMap[key] = node;
            if (cur > total){
                Node * preHead = head->next;
                hashMap.erase(preHead->key);
                removeHead();
                --cur;
            } 
        }
    }
    void removeNode(Node * node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
    }
    void removeHead(){
        Node * node = head->next;
        removeNode(node);
    }
    void addToTail(Node * node){
        node->next = tail;
        node->prev = tail->prev;
        tail->prev->next = node;
        tail->prev = node;
    }
    void moveToTail(Node * node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        addToTail(node);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */