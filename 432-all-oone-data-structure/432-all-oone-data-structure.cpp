class AllOne {
    set<pair<int,string>> hset;
    unordered_map<string,int> smap;
public:
    AllOne() {
    }
    
    void inc(string key) {
        smap[key]++;
        if(smap[key]>1){
            hset.erase({smap[key]-1,key});
        }
        hset.insert({smap[key],key});
    }
    
    void dec(string key) {
        hset.erase({smap[key],key});
        smap[key]--;
        if(smap[key]==0){
            smap.erase(key);
        }
        else
            hset.insert({smap[key],key});
        
    }
    
    string getMaxKey() {
        if(smap.empty()) return "";
        return (hset.rbegin()->second);
    }
    
    string getMinKey() {
        if(smap.empty()) return "";
        return (hset.begin()->second);
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */