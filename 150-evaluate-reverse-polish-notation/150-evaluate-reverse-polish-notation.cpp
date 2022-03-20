class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int num, a, b;
        for(string s : tokens){
            num = 0;
            bool sign = 0;
            if(s.size()>1){
                for(char c: s){
                    if(c=='-'){
                        sign = 1;
                    }
                    else{
                        num  = num * 10 + (c-'0');
                    }
                }
                if(sign) num *= -1;
                st.push(num);
            }
            else{
                if(s[0]=='+'){
                    b = st.top();
                    st.pop();
                    a = st.top();
                    st.pop();
                    st.push(a+b);
                }
                else if(s[0]=='-'){
                    b = st.top();
                    st.pop();
                    a = st.top();
                    st.pop();
                    st.push(a-b);
                }
                else if(s[0]=='/'){
                    b = st.top();
                    st.pop();
                    a = st.top();
                    st.pop();
                    st.push(a/b);
                }
                else if(s[0]=='*'){
                    b = st.top();
                    st.pop();
                    a = st.top();
                    st.pop();
                    st.push(a*b);
                }
                else{
                    num = s[0]-'0';
                    st.push(num);
                }
            }
        }
        return st.top();
    }
};