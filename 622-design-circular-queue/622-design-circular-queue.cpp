class MyCircularQueue {
    int *queue;
    int front, end, size;
public:
    MyCircularQueue(int k) {
        queue = new int[k];
        end=front=-1;
        size=k;
    }
    
    bool enQueue(int value) {
        if(front!=-1 and end==front) return false;
        if(front==-1) front=end=0;
        queue[end] = value;
        end = (end+1)%size;
        return true;
    }
    
    bool deQueue() {
        if(front==-1) return false;
        front = (front+1)%size;
        if(front==end) front=end=-1;
        return true;
    }
    
    int Front() {
        if(front==-1) return -1;
        return queue[front];
    }
    
    int Rear() {
        if(front==-1) return -1;
        if(end==0) return queue[size-1];
        return queue[end-1];
    }
    
    bool isEmpty() {
        return front==-1;
    }
    
    bool isFull() {
        return (front!=-1 and end==front);
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */