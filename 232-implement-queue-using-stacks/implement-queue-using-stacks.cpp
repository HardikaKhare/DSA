class MyQueue {
public:
stack<int>st1;
stack<int>st2;
    MyQueue() {
        
    }
    
    void push(int x) {
        int a=st1.size();
        for(int i=0;i<a;i++){
            st2.push(st1.top());
            st1.pop();
        }
        st1.push(x);
        int s=st2.size();
        for(int i=0;i<s;i++){
            st1.push(st2.top());
            st2.pop();
        }
    }
    
    int pop() {
        int t=st1.top();
        st1.pop();
        return t;
    }
    
    int peek() {
        return st1.top();
    }
    
    bool empty() {
        if(st1.size()==0)return true;
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */