class Solution {
    static bool compare(pair<int,int> &a, pair<int,int> &b){
        if(a.first==b.first) return a.second<b.second;
        return a.first < b.first;
    }
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int,int>> temp;
        for(auto tup : buildings){
            temp.push_back({tup[0],-tup[2]});
            temp.push_back({tup[1],tup[2]});
        }
        sort(temp.begin(),temp.end(),compare);
        vector<vector<int>> res;
        multiset<int, greater<int>> mset;
        int top = 0;
        mset.insert(top);
        for(int i=0;i<temp.size();i++){
            if(temp[i].second<0) mset.insert(-temp[i].second);
            else mset.erase(mset.find(temp[i].second));
            if(top != *mset.begin()){
                res.push_back({temp[i].first, *mset.begin()});
                top = *mset.begin();
            }
        }
        return res;
    }
};