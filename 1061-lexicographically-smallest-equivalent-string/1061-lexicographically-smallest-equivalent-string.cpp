class Solution {
    int par[26];
    int find(int x){
        if(par[x]==-1) return x;
        return par[x]= find(par[x]);
    }
    void combine(int a, int b){
        a = find(a);
        b = find(b);
        if(a!=b){
            par[max(a,b)] = min(a,b);
        }
    }
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        memset(par,-1,sizeof par);
        for(int i=0;i<s1.size();i++)
            combine(s1[i]-'a',s2[i]-'a');
        for(int i=0;i<baseStr.size();i++)
            baseStr[i] = find(baseStr[i]-'a')+'a';
        return baseStr;
    }
};