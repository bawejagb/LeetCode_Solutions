class LRUCache{
	unordered_map<int, list<pair<int,int>>::iterator> LRUTrack;
	int cap;
	list<pair<int,int>> LRUList;
	public:
		
	LRUCache(int capacity){
		cap = capacity;
	}	
	int get(int key){
		if(LRUTrack.find(key)!=LRUTrack.end()){
			LRUList.splice(LRUList.begin(),LRUList,LRUTrack[key]);
			return LRUTrack[key]->second;
		}
		return -1;
	}
	void put(int key, int value){
		if(LRUTrack.find(key)!=LRUTrack.end()){
			LRUList.splice(LRUList.begin(),LRUList, LRUTrack[key]);
			LRUTrack[key]->second = value;
			return;
		}
		else if(LRUTrack.size()==cap){
			LRUTrack.erase(LRUList.back().first);
			LRUList.pop_back();
		}
		LRUList.push_front({key,value});
		LRUTrack[key] = LRUList.begin();
	}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */