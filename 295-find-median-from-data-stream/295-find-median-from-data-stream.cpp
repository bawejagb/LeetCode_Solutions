class MedianFinder {
    priority_queue<int> maxh;
    priority_queue<int, vector<int>, greater<int>> minh;
    int n;
public:
    MedianFinder() {
       n=0;
    }
    
    void addNum(int num) {
     if(n&1){
            if(num<maxh.top()){
                minh.push(maxh.top());maxh.pop();
                maxh.push(num);
            }
            else
                minh.push(num);
            n++;
        }
        else{
            if(n==0){
                maxh.push(num);
                n++;
                return;
            }
            if(num>maxh.top() && num>minh.top()){
                maxh.push(minh.top());minh.pop();
                minh.push(num);
            }
            else
                maxh.push(num);
            n++;
        }
    }
    
    double findMedian() {
       double med;
        if(n&1)
            med = maxh.top();
        else
            med = double(maxh.top()+minh.top())/2;
        return med;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */