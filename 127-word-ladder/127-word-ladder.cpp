class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,vector<string>> hmap;
        int n = wordList.size();
        int sz = beginWord.size();
        for(int i = 0; i < n; i++){
            for(int j=0;j<sz;j++){
                string s = wordList[i].substr(0,j)+"*"+wordList[i].substr(j+1,sz-j-1);
                hmap[s].push_back(wordList[i]);
            }
        }
        for(int i=0;i<sz;i++){
            string s = beginWord.substr(0,i)+"*"+beginWord.substr(i+1,sz-i-1);
            hmap[s].push_back(beginWord);
        }
        queue<string> qt;
        qt.push(beginWord);
        unordered_set<string> st;
        st.insert(beginWord);
        int res=1;
        while(!qt.empty()){
            int len = qt.size();
            while(len--){
                string s = qt.front();
                qt.pop();
                for(int i=0;i<sz;i++){
                    string t = s.substr(0,i)+"*"+s.substr(i+1,sz-i-1);
                    for(string p : hmap[t]){
                        if(st.count(p)==0){
                            st.insert(p);
                            qt.push(p);
                        }
                    }
                }
            }
            res++;
            if(st.count(endWord)) return res;
        }
        return 0;
    }
};