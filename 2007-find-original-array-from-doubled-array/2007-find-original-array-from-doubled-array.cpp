class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if(changed.empty() || changed.size() % 2 != 0) return {};
        unordered_map<int, int> map;
        vector<int> result;
        for(auto i : changed) map[i]++;
        sort(changed.begin(), changed.end());
        for(auto i : changed){
            if(map.count(i*2) && map[i*2] > 0 && map[i] > 0){
                result.push_back(i);
                --map[i];
                --map[i*2];
            }
        }
        for(auto i : map){
            if(i.second != 0)
                return {};
        }
        return result;
    }
};