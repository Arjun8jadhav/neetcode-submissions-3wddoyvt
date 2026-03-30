class MinStack {
    vector<int> st;
    vector<int> top_;
public:
    MinStack() {
        
    }
    int mini=INT_MAX;
    void push(int val) {
        mini=min(val,mini);
        st.push_back(mini);
        top_.push_back(val);

    }
    
    void pop() {
        st.pop_back();
        top_.pop_back();
        if(st.size()==0){
            mini=INT_MAX;
        }
        else{
            mini=st.back();
        }
        
    }
    
    int top() {
        return top_.back();
    }
    
    int getMin() {
        return st.back();
    }
};
