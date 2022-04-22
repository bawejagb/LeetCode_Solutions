class Node{
    public:
    int val = 0;
    int key = 0;
    int frequency = 1;
    Node* prev = nullptr;
    Node* next = nullptr;
    Node(int k, int v){
        key = k;
        val = v;
    }
};
class DoublyLinkedList{
    public:
    Node* head = nullptr;
    Node* tail = nullptr;
    int size = 0;
    DoublyLinkedList(){
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
};
class LFUCache {
public:
    int capacity = 0;
    int size = 0;
    int minFreq = 0;
    unordered_map<int, DoublyLinkedList*> freqDll; //freq, doublyLinkedList
    unordered_map<int, Node*> freqNode; //key, Node
    
    LFUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(freqNode.find(key) == freqNode.end()) return -1;
        else{
            Node* curr = freqNode[key];
            //change Node object
            curr->frequency++;
            //remove from previous dll
            Node* p = curr->prev;
            Node* n = curr->next;
            p->next = n;
            n->prev = p;
            //decrease size of previous dll
            DoublyLinkedList* crlist = freqDll[curr->frequency-1];
            crlist->size--;
            //check for empty list
            if(crlist->size <= 0){
                if(curr->frequency-1 == minFreq) minFreq++;
                freqDll.erase(curr->frequency-1);
            }
            //add to new list
            if(freqDll.find(curr->frequency) == freqDll.end()) freqDll.insert({curr->frequency, new DoublyLinkedList()});
            DoublyLinkedList* newlist = freqDll[curr->frequency];

            //add node to new list
            newlist->size++;
            curr->next = newlist->head->next;
            curr->next->prev = curr;
            newlist->head->next = curr;
            curr->prev = newlist->head;
            return curr->val;
        }
    }
    
    void put(int key, int value) {
        if(freqNode.find(key) == freqNode.end()){
            if(size < capacity){
                size++;
                //create new node
                Node* curr = new Node(key, value);
                freqNode.insert({key, curr});
                minFreq = 1;
                if(freqDll.find(1) == freqDll.end()) freqDll.insert({1, new DoublyLinkedList()});
                DoublyLinkedList* curlist = freqDll[1];
                curlist->size++;
                curr->next = curlist->head->next;
                curr->next->prev = curr;
                curlist->head->next = curr;
                curr->prev = curlist->head;
            }else{
                //delete less frequent and create new
                if(freqDll.find(minFreq) == freqDll.end()) return;
                DoublyLinkedList* curlist = freqDll[minFreq];
                curlist->size--;
                Node* todelete = curlist->tail->prev;
                freqNode.erase(todelete->key);
                todelete->prev->next = todelete->next;
                todelete->next->prev = todelete->prev;
                delete todelete;
                minFreq = 1;
                
                Node* curr = new Node(key, value);
                freqNode.insert({key, curr});
                if(freqDll.find(1) == freqDll.end()) freqDll.insert({1, new DoublyLinkedList()});
                DoublyLinkedList* curlist2 = freqDll[1];
                curlist2->size++;
                curr->next = curlist2->head->next;
                curr->next->prev = curr;
                curlist2->head->next = curr;
                curr->prev = curlist2->head;
            }
        }else{
            Node* curr = freqNode[key];
            //change Node object
            curr->frequency++;
            curr->val = value;
            //remove from previous dll
            Node* p = curr->prev;
            Node* n = curr->next;
            p->next = n;
            n->prev = p;
            //decrease size of previous dll
            DoublyLinkedList* crlist = freqDll[curr->frequency-1];
            crlist->size--;
            //check for empty list
            if(crlist->size <= 0){
                if(curr->frequency-1 == minFreq)
                minFreq++;
                freqDll.erase(curr->frequency-1);
            }
            //add to new list
            if(freqDll.find(curr->frequency) == freqDll.end()) freqDll.insert({curr->frequency, new DoublyLinkedList()});
            DoublyLinkedList* newlist = freqDll[curr->frequency];

            //add node to new list
            newlist->size++;
            curr->next = newlist->head->next;
            curr->next->prev = curr;
            newlist->head->next = curr;
            curr->prev = newlist->head;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */