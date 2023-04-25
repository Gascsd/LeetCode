//https://leetcode.cn/problems/min-stack/
#include <iostream>
#include <stack>
using namespace std;
class MinStack {
public:
    MinStack() {

    }

    void push(int val) {
        _st.push(val);
        if (_minst.empty() || val <= _minst.top())
        {
            _minst.push(val);
        }
    }

    void pop() {
        if (_st.top() == _minst.top())
        {
            _minst.pop();
        }
        _st.pop();
    }

    int top() {
        return _st.top();
    }

    int getMin() {
        return _minst.top();
    }
    stack<int> _st;
    stack<int> _minst;
};
int main()
{
    MinStack st;
    st.push(-2);
    st.push(0);
    st.push(-3);
    cout << st.getMin() << endl;
    st.pop();
    cout << st.top() << endl;
    cout << st.getMin() << endl;

    return 0;
 }