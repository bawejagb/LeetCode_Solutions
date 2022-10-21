class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        map<int,int> hmap;
        priority_queue<pair<int,int>> pq;
        for(int num : nums) hmap[num]++;
        for(auto [a,b]: hmap)
            pq.push({b,a});
        while(k--){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};