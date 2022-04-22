class LFUCache {
  struct KV {
    int key;
    int value;
    int freq;
    KV() {}
    KV(int k, int v, int f = 1) : key(k), value(v), freq(f) {}
  };

  std::map<int, std::list<KV>> freq2kv_;
  std::unordered_map<int, std::list<KV>::iterator> key2pos_;
  int capacity_;

 public:
  LFUCache(int capacity) : capacity_(capacity) {}

  int get(int key) {
    auto it_key2pos = key2pos_.find(key);
    if (it_key2pos == key2pos_.end()) {
      return -1;
    }
    auto it_kv = it_key2pos->second;
    auto kv = *it_kv;
    int ret = kv.value;
    int old_freq = kv.freq++;
    auto it_freq2kv = freq2kv_.find(old_freq);
    it_freq2kv->second.erase(it_kv);
    if (it_freq2kv->second.empty()) {
      freq2kv_.erase(it_freq2kv);
    }
    auto& kv_list = freq2kv_[kv.freq];
    auto it_list = kv_list.insert(kv_list.begin(), kv);
    key2pos_[key] = it_list;

    return ret;
  }

  void put(int key, int value) {
    if (!capacity_) {
      return;
    }
    auto it_key2pos = key2pos_.find(key);
    // Evict
    if (key2pos_.size() == capacity_ && it_key2pos == key2pos_.end()) {
      auto& kv_list = freq2kv_.begin()->second;
      auto kv = kv_list.back();
      kv_list.pop_back();
      if (kv_list.empty()) {
        freq2kv_.erase(freq2kv_.begin());
      }
      key2pos_.erase(kv.key);
    }

    // Insert
    if (it_key2pos == key2pos_.end()) {
      auto& kv_list = freq2kv_[1];
      auto pos = kv_list.insert(kv_list.begin(), KV(key, value));
      key2pos_.insert({key, pos});
    } else {
      // Update
      auto it_kv = it_key2pos->second;
      auto kv = *it_kv;
      kv.value = value;
      int old_req = kv.freq++;
      auto it_freq2kv = freq2kv_.find(old_req);
      it_freq2kv->second.erase(it_kv);
      if (it_freq2kv->second.empty()) {
        freq2kv_.erase(it_freq2kv);
      }
      auto& kv_list = freq2kv_[kv.freq];
      it_kv = kv_list.insert(kv_list.begin(), kv);
      key2pos_[key] = it_kv;
    }
  }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */