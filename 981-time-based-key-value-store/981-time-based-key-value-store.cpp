class TimeMap {
    unordered_map<string,vector<pair<int,string>>> hmap;
    static bool cmp(const int &t, const pair<int, string> &p) {
                    return t < p.first;
    }
public:
    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        hmap[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        const auto& v = hmap[key];
        auto it = upper_bound(v.begin(), v.end(), timestamp, cmp);
        return it == v.begin() ? "" : (--it)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */