class MinStack {
public:
vector<int>st;
vector<int>mini;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push_back(val);
        int minim=INT_MAX;
        for(int i=0;i<st.size();i++){
            minim=min(minim,st[i]);
        }
        mini.push_back(minim);
    }
    
    void pop() {
        st.pop_back();
        mini.pop_back();
    }
    
    int top() {
        int s=st.size()-1;
        return st[s];
    }
    
    int getMin() {
        int s=st.size()-1;
        return mini[s];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */