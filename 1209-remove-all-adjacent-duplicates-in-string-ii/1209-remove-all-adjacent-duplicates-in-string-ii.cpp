class Solution {
public:
    string removeDuplicates(string s, int k) {
        string res="";
        stack<pair<char,int>> st;
        for(char c : s){
            if(st.empty()||st.top().first!=c){
                st.push({c,1});
            }
            else{
                st.top().second++;
            }
            if(st.top().second==k)
                    st.pop();
        }
        while(!st.empty()){
            auto prev = st.top();
            st.pop();
            while(prev.second--)
                res.push_back(prev.first);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};