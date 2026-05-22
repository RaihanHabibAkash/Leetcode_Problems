class MyQueue {
public:
int first = -1;
stack<int> st;

    MyQueue() {
        
    }
    
    void push(int x) {
        st.push(x);
        if(first == -1) first = x;
    }
    
    int pop() {
        stack<int> st2;
        int val;
        while(!st.empty()) {
            val = st.top();
            st.pop();
            if(st.empty()) break;
            else st2.push(val);
        }
        first = st2.top();
        while(!st2.empty()) {
            st.push(st2.top());
            st2.pop();
        }
        return val;
    }
    
    int peek() {
        return first;
    }
    
    bool empty() {
        return st.empty();
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