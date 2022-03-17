class StockSpanner {
    stack<pair<int,int>> st;
    int cnt;
public:
    StockSpanner() {
        cnt=0;
    }
    
    int next(int price) {
        int res=cnt+1;
        while(!st.empty()&&st.top().second<=price)
            st.pop();
        if(!st.empty())
            res -= st.top().first;
        st.push({cnt+1,price});
        cnt++;
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */