class StockSpanner {
    stack<pair<int,int>> st;
    int cnt;
public:
    StockSpanner() {
        cnt=1;
    }
    
    int next(int price) {
        cnt=1;
        if(st.empty()){
            st.push({cnt,price});
        }
        else{
            while(!st.empty()){
                auto x = st.top();
                if(x.second<=price){
                    cnt += x.first;
                    st.pop();
                }
                else break;
            }
            st.push({cnt,price});
        }
        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */