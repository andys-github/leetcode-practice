class MyStack {
private:
    queue<int> primaryQueue;
    queue<int> secondaryQueue;
public:
    MyStack() {
        primaryQueue = {};
        secondaryQueue = {};
    }
    
    void push(int x) {
        primaryQueue.push(x);
        while(primaryQueue.size() != 1) {
            int temp = primaryQueue.front();
            primaryQueue.pop();
            secondaryQueue.push(temp);
        }

        while(secondaryQueue.size() != 0) {
            int temp = secondaryQueue.front();
            secondaryQueue.pop();
            primaryQueue.push(temp);
        }
    }
    
    int pop() {
        int front = primaryQueue.front();
        primaryQueue.pop();
        return front;
    }
    
    int top() {
        return primaryQueue.front();
    }
    
    bool empty() {
        return primaryQueue.size() == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */