class MinStack {
private:
    stack<int> normal_stk;
    stack<int> min_stk;

public:
    void push(int x) {
        normal_stk.push(x);
        if(min_stk.empty() || x <= min_stk.top())
            min_stk.push(x);
    }

    void pop() {
        int tmp = normal_stk.top();
        normal_stk.pop();
        if(tmp == min_stk.top())
            min_stk.pop();
    }

    int top() {
        return normal_stk.empty() ? -1 : normal_stk.top();
    }

    int getMin() {
        return min_stk.empty() ? -1 : min_stk.top();
    }
};