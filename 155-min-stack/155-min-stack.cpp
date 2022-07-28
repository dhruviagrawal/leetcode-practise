class MinStack {
    stack<long long>st;
    long long mini;
public:
    MinStack() {
        while(!st.empty())
            st.pop();
        mini=INT_MAX;
    }
    
    void push(int value) {
        long long val=value;
        if(st.empty())
        {
            st.push(val);
            mini=val;
        }
        else
        {
            if(val>mini)
                st.push(val);
            else
            {
                st.push(2*val*1LL-mini);
                    mini=val;
            }
        }
    }
    
    void pop() {
        if(st.empty())
            return;
        if(st.top()>mini)
            st.pop();
        else
        {
            mini=2*mini*1LL-st.top();
            st.pop();
        }
    }
    
    int top() {
        if(st.empty())
            return -1;
        
        if(st.top()>mini)
            return st.top();
        else
            return mini;
    }
    
    int getMin() {
        return mini;
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