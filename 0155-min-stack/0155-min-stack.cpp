class MinStack {
public:
//Methods pop, top and getMin operations will always be called on non-empty stacks.(IMP CONDITION GIVEN IN QUE) SO NO NEED TO CHECK EMPTY OR UNDERFLOW AND OVERFLOW
    vector<pair<int,int>>st;
    MinStack() {
        
    }
    
    void push(int val) {
        //when stack is empty
        if(st.empty()){
            pair<int,int>p;
            p.first = val;
            p.second = val;//second is for storing min and if stack is empty then first element is min itself
            st.push_back(p);
        }
        else{
            pair<int,int>p;
            p.first = val;
            int rightMostElementkaMin = st.back().second;
            p.second = min(val, rightMostElementkaMin);
            st.push_back(p);
        }
        return;
    }
    
    void pop() {
        st.pop_back();
        return;
    }
    
    int top() {
       return st.back().first;
    }
    
    int getMin() {
        return st.back().second;
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
