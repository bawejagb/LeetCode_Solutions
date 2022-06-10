class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int v[256]{};
        int a=0,m=0;
        for(int i=0;i<s.size();i++)
        {
            if(v[s[i]] > a)
            {
                a=v[s[i]];
            }
            v[s[i]]=i+1;
            m=max(m,i-a+1);
        }
        return m;
    }
};