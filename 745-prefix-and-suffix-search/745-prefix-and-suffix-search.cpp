class WordFilter {
    unordered_map<string,int> hmap;
public:
    WordFilter(vector<string>& words) {
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].size();j++){
                for(int k=0;k<words[i].size();k++){
                string s = words[i].substr(0,j+1)+'#'+words[i].substr(k,words[i].size());
                hmap[s] = i;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        string s = prefix+'#'+suffix;
        return hmap.find(s)==hmap.end()?-1:hmap[s];
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */