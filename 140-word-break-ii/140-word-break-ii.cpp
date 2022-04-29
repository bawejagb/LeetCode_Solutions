class Solution {
    vector<string> vs;
    void dfs(string s, string res, vector<string>&wordDict){
        if(s.empty()){
            if(!res.empty()) vs.push_back(res);
            return;
        }
        for(int i=0;i<wordDict.size();i++){
            if(s.find(wordDict[i])==0){
                if(res.empty())
                    dfs(s.substr(wordDict[i].size()), res+wordDict[i], wordDict);
                else
                    dfs(s.substr(wordDict[i].size()), res+" "+wordDict[i], wordDict);
            }
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        string res;
        dfs(s,res,wordDict);
        return vs;
    }
};