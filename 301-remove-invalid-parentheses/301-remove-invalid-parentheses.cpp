class Solution {
    void dfs(int p, int lastRm, string dir, string s, vector<string>& res) {
        for(int i=p, count=0;i<s.size();i++) {
            if(s[i]==dir[0]) count++;
            else if(s[i]==dir[1]) count--;
            if(count>=0) continue;
            for(int j=lastRm;j<=i;j++)
                if(s[j]==dir[1] && (j==lastRm || s[j-1]!=dir[1]))
                    dfs(i,j,dir,s.substr(0,j)+s.substr(j+1),res);
            return;        
        }
        reverse(s.begin(),s.end());
        if(dir[0]=='(') dfs(0,0,")(",s,res);
        else res.push_back(s);
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        dfs(0,0,"()",s,res);
        return res;
    }
};