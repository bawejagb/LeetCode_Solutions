class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c: s){
            if(c==')'&&!st.empty()&&st.top()=='('){
                st.pop();
            }
            else if(c=='}'&&!st.empty()&&st.top()=='{'){
                st.pop();
            }
            else if(c==']'&&!st.empty()&&st.top()=='['){
                st.pop();
            }
            else if(c=='['||c=='{'||c=='(')
                st.push(c);
            else return false;
        }
        return st.empty();
    }
};