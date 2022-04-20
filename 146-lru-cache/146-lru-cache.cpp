class LRUCache {
    unordered_map<int,list<pair<int,int>>::iterator> track;
    int cap;
    list<pair<int,int>> lruList; 
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(track.find(key)!=track.end()){
            lruList.splice(lruList.begin(),lruList, track[key]);
            return track[key]->second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(track.find(key)!=track.end()){
            lruList.splice(lruList.begin(),lruList,track[key]);
            track[key]->second = value;
            return;
        }
        else if(track.size()==cap){
            track.erase(lruList.back().first);
            lruList.pop_back();
        }
        lruList.push_front({key,value});
        track[key] = lruList.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */