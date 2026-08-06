class MinStack {
public:
    stack<int>st;
    stack<int>minStack;

    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);

        if(minStack.empty())
        minStack.push(val);
        else{
            if(minStack.top()>=val)
            minStack.push(val);
        }
    }
    
    void pop() {
         
         if(st.top()==minStack.top()){
            minStack.pop();
         }

        st.pop(); 
    }
    
    int top() {
        if(!st.empty())
        return st.top();
    }
    
    int getMin() {
        if(!minStack.empty())
        return minStack.top();
    }
};
