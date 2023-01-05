class TrieNode{
    TrieNode *link[26];
    bool endNode;
    public:
    bool containKey(char ch){
        return link[ch-'a'] != NULL;
    }
    TrieNode* get(char ch){
        return link[ch-'a'];
    }
    void put(char ch, TrieNode* node){
        link[ch-'a'] = node;
    }
    void setEnd(){
        endNode = true;
    }
    bool isEnd(){
        return endNode;
    }
};
class Trie {
    TrieNode *root;
public:
    Trie() {
         root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for(char c : word){
            if(!node->containKey(c)){
                node->put(c, new TrieNode());
            }
            node = node->get(c);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for(char c : word){
            if(node->containKey(c))
                node = node->get(c);
            else{
                node = NULL;
                break;
            }
        }
        return node != NULL and node->isEnd();
        
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(char c : prefix){
            if(node->containKey(c))
                node = node->get(c);
            else{
                node = NULL;
                break;
            }
        }
        return node != NULL;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */