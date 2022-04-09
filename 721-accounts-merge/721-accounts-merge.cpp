class Solution {
    unordered_map<string,vector<string>> hmap;
    void dfs(set<string> &hset, vector<string> &temp, string s){
        if(hset.find(s)!=hset.end()) return;
        hset.insert(s);
        temp.push_back(s);
        for(auto x: hmap[s]){
            dfs(hset, temp, x);
        }
     }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> res;
        for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
                if(j+1<accounts[i].size())
                    hmap[accounts[i][j]].push_back(accounts[i][j+1]);
                if(j>1)
                    hmap[accounts[i][j]].push_back(accounts[i][j-1]);
            }
        }
        set<string> hset;
        for(int i=0;i<accounts.size();i++){
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            dfs(hset, temp, accounts[i][1]);
            sort(temp.begin()+1,temp.end());
            if(temp.size()>1)
                res.push_back(temp);
        }
        return res;
    }
};