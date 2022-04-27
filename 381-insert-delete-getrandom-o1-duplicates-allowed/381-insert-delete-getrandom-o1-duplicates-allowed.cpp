class RandomizedCollection {
    unordered_map<int,set<int>> hmap;
    vector<int> vc;
    int sz;
public:
    RandomizedCollection() {
        sz=0;
    }
    
    bool insert(int val) {
        bool fg;
        if(hmap.find(val)==hmap.end()) fg=1;
        else fg=0;
        vc.push_back(val);
        hmap[val].insert(sz);
        sz++;
        return fg;
    }
    bool remove(int val) {
        bool fg;
        if(hmap.find(val)!=hmap.end()){
            fg=1;
            int idx = *hmap[val].begin();
            hmap[val].erase(hmap[val].begin());
            if(hmap[val].empty()) hmap.erase(val);
            if(sz==1||idx==sz-1){
                sz--;
                vc.resize(sz);
                return true;
            }
            vc[idx] = vc[sz-1];
            auto it = hmap[vc[sz-1]].end();
            --it;
            hmap[vc[sz-1]].erase(it);
            hmap[vc[sz-1]].insert(idx);
            sz--;
            vc.resize(sz);
        }
        else fg=0;
        return fg;
    }
    
    int getRandom() {
        return vc[rand()%sz];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */