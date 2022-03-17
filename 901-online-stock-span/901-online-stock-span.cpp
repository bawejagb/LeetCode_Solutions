class StockSpanner {
    stack<pair<int,int>> st;
    vector<int> stk;
    int idx,cnt;
public:
    StockSpanner() {
        idx=0;
        cnt=1;
    }
    
    int next(int price) {
        cnt=1;
        if(st.empty()){
            st.push({idx,price});
            stk.push_back(1);
        }
        else{
            stk.push_back(1);
            while(!st.empty()){
                auto x = st.top();
                if(x.second<=price){
                    cnt += stk[x.first];
                    st.pop();
                }
                else break;
            }
            st.push({idx,price});
        }
        stk[idx]=cnt;
        idx++;
        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */