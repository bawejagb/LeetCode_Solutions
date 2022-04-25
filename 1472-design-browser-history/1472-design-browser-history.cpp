class BrowserHistory {
    vector<string> hist;
    int index;
public:
    BrowserHistory(string homepage) {
        hist.push_back(homepage);
        index = 0;
    }
    
    void visit(string url) {
        hist.resize(index+2);
        index++;
        hist[index] = url;
        
    }
    
    string back(int steps) {
        index = max(0,index-steps);
        return hist[index];
    }
    
    string forward(int steps) {
        index = min((int)(index+steps), (int)(hist.size()-1));
        return hist[index];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */