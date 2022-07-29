class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        int n = words.size();
        int s = pattern.size();
        vector<string> ans ;
        vector<int> vt(26,0);
        unordered_map<char,char> mp;
        for(int i =0;i<n;i++){
            string x = words[i];
            int j ;
            for(j = 0;j<s;j++){
                if(mp.find(pattern[j])==mp.end()){
                    if(vt[x[j]-'a'] == 1) break;
                    mp[pattern[j]] = x[j];
                    vt[x[j]-'a'] = 1;
                }
                else{
                    char p = mp[pattern[j]];
                    if(p!=x[j]) break;
                }
            }
            if(j==s){
                ans.push_back(words[i]);
            }
            mp.clear(); 
            vt = vector<int>(26,0);
        }
        return ans ;
    }
};