class MyCalendarThree {
    map<int,int> hmap;
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        hmap[start]++;
        hmap[end]--;
        int res=0,cur=0;
        for(auto &[a,b] : hmap){
            cur += b;
            res = max(res,cur);
        }
        return res;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */