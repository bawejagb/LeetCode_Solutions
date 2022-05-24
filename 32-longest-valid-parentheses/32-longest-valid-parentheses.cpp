class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size();
        int ans=0;
        int left=0,right=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]==')')           right++;
            else if(s[i]=='(')      left++;
            if(left==right)         ans=max(left+right,ans);
            else if(right>left)     left=right=0;
        }
        
        left=right=0;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='(')        left++;
            else if(s[i]==')')   right++;
            if(left==right)      ans=max(left+right,ans);
            else if(right<left)  left=right=0;
        }
        return ans;
    }
};