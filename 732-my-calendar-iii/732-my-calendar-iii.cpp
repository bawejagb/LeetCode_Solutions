class MyCalendarThree {
    unordered_map<int,int> vals, lazy;
    void update(int start, int end, int left, int right, int idx){
        if(start>right || end < left) return;
        if(start <= left and end >= right){
            vals[idx]++;
            lazy[idx]++;
        }
        else{
            int mid= (left+right)/2;
            update(start, end, left, mid, idx*2);
            update(start, end, mid+1, right, idx*2+1);
            vals[idx] = lazy[idx]+max(vals[idx*2], vals[idx*2+1]);
        }
    }
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        update(start, end-1, 1, 1e9, 1);
        return vals[1];
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */