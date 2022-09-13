class Solution {
    unordered_set<string> ans;
    bool isValid(string & st){
        int n = st.size();
        int cnt = 0;
        for(int i = 0; i< n; i++){
            if(st[i]=='(') cnt++;
            else if(st[i]==')') cnt--;
            if(cnt < 0) return false;
        }
        return cnt == 0;
    }
    void dfs(string s, int idx, string st, int inValidCount, int totalInValid){
        if(idx==s.size()){
            if(isValid(st))
                ans.insert(st);
            return;
        }
        if(totalInValid-inValidCount==s.size()-idx){
            dfs(s,s.size(),st,totalInValid, totalInValid);
            return;
        }
        if(inValidCount == totalInValid){
            string temp = st+s.substr(idx);
            dfs(s,s.size(),temp, inValidCount, totalInValid);
            return;
        }
        st += s[idx];
        dfs(s,idx+1, st, inValidCount, totalInValid);
        st.pop_back();
        if(s[idx]!='(' and s[idx]!=')') return;
        dfs(s,idx+1, st, inValidCount+1, totalInValid);
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        int n = s.size(), cnt = 0;
        int totalInValid = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                if(cnt<0) cnt = 1;
                else cnt++;
            }
            else if(s[i]==')') cnt--;
            if(cnt<0 and s[i]==')') totalInValid++;
        }
        cnt = 0;
        for(int i=n-1;i>=0;i--){
            if(s[i]==')'){
                if(cnt<0) cnt = 1;
                else cnt++;
            }
            else if(s[i]=='(') cnt--;
            if(cnt<0 and s[i] =='(') totalInValid++;
        }
        string st;
        dfs(s,0,st,0,totalInValid);
        vector<string> res;
        for(auto &i : ans){
            res.push_back(i);
        }
        return res;
    }
};