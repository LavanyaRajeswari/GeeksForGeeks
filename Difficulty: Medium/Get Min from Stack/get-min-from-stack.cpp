class SpecialStack {
  public:
    stack<int>st;
    map<int,int>mp;
    SpecialStack() {
        // Define Stack
    }

    void push(int val) {
        st.push(val);
        mp[val]++;
    }

    void pop() {
        if(!st.empty()) {
            mp[st.top()]--;
            if(mp[st.top()] == 0)mp.erase(st.top());
            st.pop();
        }
    }

    int peek() {
        return (!st.empty()) ? st.top() : -1;
    }

    bool isEmpty() {
        return (!st.empty()) ? false : true;
    }

    int getMin() {
        int n = -1;
        for(auto it:mp) {
            n = it.first;
            break;
        }
        return n;
    }
};