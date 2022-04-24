class AllOne {
    map<int, set<string>> hmap;
    unordered_map<string,int> smap;
    int mn, mx;
public:
    AllOne() {
        mn=mx=0;
    }
    
    void inc(string key) {
        smap[key]++;
        if(smap[key]>1){
            if(hmap[smap[key]-1].size()==1)
                hmap.erase(smap[key]-1);
            else
                hmap[smap[key]-1].erase(key);
        }
        hmap[smap[key]].insert(key);
    }
    
    void dec(string key) {
        if(hmap[smap[key]].size()==1)
            hmap.erase(smap[key]);
        else
            hmap[smap[key]].erase(key);
        smap[key]--;
        if(smap[key]==0){
            smap.erase(key);
        }
        else
            hmap[smap[key]].insert(key);
        
    }
    
    string getMaxKey() {
        if(smap.empty()) return "";
        return *(hmap.rbegin()->second).begin();
    }
    
    string getMinKey() {
        if(smap.empty()) return "";
        return *(hmap.begin()->second).begin();
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