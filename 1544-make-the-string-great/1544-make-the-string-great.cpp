class Solution {
public:
    string makeGood(string s) {
        int n = s.size();
        string res;
        stack<char> st;
        st.push(s[0]);
        for(int i=1;i<n;i++){
            if(!st.empty() and (s[i]-'a'==st.top()-'A' || s[i]-'A'==st.top()-'a')){
                st.pop();
                continue;
            }
            st.push(s[i]);
        }
        while(!st.empty()){
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};