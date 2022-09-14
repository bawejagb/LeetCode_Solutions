class Solution {
    unordered_set<string> hset;
    bool dfs(string word){
        for(int i = 1; i < word.size(); i++){
            string suffex = word.substr(i);
            if(hset.find(word.substr(0,i))!=hset.end() and (hset.find(suffex)!=hset.end() || dfs(word.substr(i))))
                return true;
        }
        return false;
    }
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> res;
        for(string word : words) hset.insert(word);
        for(string word: words){
            if(dfs(word))
                res.push_back(word);
        }
        return res;
    }
};