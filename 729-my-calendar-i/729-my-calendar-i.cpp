class MyCalendar {
public:
    set<pair<int,int>> hset;
    MyCalendar() {

    }
    
    bool book(int start, int end) {
        auto it = hset.lower_bound({start,end});
        bool ans;
        if(it==hset.end()){
            if(hset.size()){
            auto it1=it;
            it1--;
            if(start>=(*it1).second) ans=true;
            else ans =false;
            }else
            ans=true;
        }
        else if(it==hset.begin()){
            if(end<=(*it).first) ans= true;
            else ans=false;
        }else{
            auto it1=it;
            it1--;
            if(end<=(*it).first&&start>=(*it1).second) ans=true;
            else ans =false;
        }
        if(ans)
        hset.insert({start,end});
        return ans;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */