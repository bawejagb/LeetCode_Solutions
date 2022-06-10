class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>v(256,-1);
        int a=-1,m=0;
        for(int i=0;i<s.size();i++)
        {
            if(v[s[i]] > a)
            {
                a=v[s[i]];
            }
            v[s[i]]=i;
            m=max(m,i-a);
        }
        return m;
    }
};