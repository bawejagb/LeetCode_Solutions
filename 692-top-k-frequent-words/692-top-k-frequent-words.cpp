class compare{
  public:
    bool operator() (pair<string,int> a, pair<string,int> b){
        if(a.second!=b.second)
            return a.second<b.second;
        return a.first>b.first;
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> hmap;
        for(string w : words)
            hmap[w]++;
        priority_queue<pair<string,int>,vector<pair<string,int>>,compare> pQueue;
        vector<string> res;
        for(auto p: hmap)
            pQueue.push(p);
        while(k--){
            res.push_back(pQueue.top().first);
            pQueue.pop();
        }
        return res;
    }
};