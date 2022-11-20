class Solution {
public:
    int calculate(string s) {
        int sum =0;
        int sign = 1;
        stack<int>st;
        
        for(int i =0;i<s.size();i++){
            char ch = s[i];
            if(ch>='0' && ch<='9'){
                int val =0;
                while(i<s.length() && s[i]>='0' && s[i]<='9'){
                    val=(val*10)+(s[i]-'0');
                    i++;
                }
                i--;
                val=val*sign;
                sum+=val;
                sign=1;
            }else if(ch=='('){
                st.push(sum);
                st.push(sign);
                sum=0;
                sign= +1;
            }else if(ch==')'){
                int a = st.top();
                st.pop();
                sum*=a;
                int b= st.top();
                st.pop();
                sum+=b;
            }else if(ch=='-'){
                sign*=-1;
            }
        }
       return sum;
    }
};