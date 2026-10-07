class MinStack {
public:
    stack<int> st;
    stack<int> st1;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st1.size()==0){
            st1.push(val);
        }
        else{
            int mini=min(val,st1.top());
            st1.push(mini);
        }
        st.push(val);
        
        
    }
    
    void pop() {
        st1.pop();
        st.pop();

    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return st1.top();
    }
};
