class MyQueue {
public:
    stack<int>in,out;
    MyQueue() {
        
    }
    
    void push(int x) {
        in.push(x);
    }
    
    int pop() {
         if(!out.empty())
         {
             int t=out.top();
             out.pop();
             return t;
         }
        else
        {
            while(!in.empty())
            {
                out.push(in.top());
                in.pop();
            }
            int t=out.top();
             out.pop();
             return t;
        }
    }
    
    int peek() {
        if(!out.empty())
            return out.top();
        else
        {
            while(!in.empty())
            {
                out.push(in.top());
                in.pop();
            }
            return out.top();
        }
    }
    
    bool empty() {
        if(out.size()==0 && in.size()==0)
            return true;
        else
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