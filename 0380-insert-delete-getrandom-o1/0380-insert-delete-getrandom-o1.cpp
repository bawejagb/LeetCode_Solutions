class RandomizedSet {
  unordered_map<int,int> hmap;
    vector<int> num;
public:
    RandomizedSet() {

    }
    
    bool insert(int val) {
        if(hmap.find(val) == hmap.end()){
            num.emplace_back(val);
            hmap[val] = num.size()-1;
            return true;
        }
        return false;
    }
    
    
    bool remove(int val) {
    if(hmap.find(val) != hmap.end()){
        int last = num.back();
        num[hmap[val]]  = last;
        hmap[last] = hmap[val];
        num.pop_back();
        hmap.erase(val);
        return true;
    }
        return false;
    }
    
    int getRandom() {
        return num[rand()%num.size()];
        
    }
};
/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */