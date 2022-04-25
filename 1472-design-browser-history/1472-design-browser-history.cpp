class BrowserHistory {
    struct Node{
        string url;
        Node* next;
        Node* prev;
        Node(string url){this->url=url;next=NULL;prev=NULL;}
    };
    Node* current;
public:
    BrowserHistory(string homepage) {
        current = new Node(homepage);
    }
    
    void visit(string url) {
        current->next = new Node(url);
        current->next->prev = current;
        current = current->next;
        
    }
    
    string back(int steps) {
        while(steps--){
            if(!current->prev) break;
            current = current->prev;
        }
        return current->url;
    }
    
    string forward(int steps) {
        while(steps--){
            if(!current->next) break;
            current = current->next;
        }
        return current->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */