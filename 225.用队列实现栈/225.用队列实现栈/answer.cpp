#include <iostream>
#include <queue>
using namespace std;


class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    MyStack() {

    }

    void push(int x) {//这里在结构上保证必须有一个队列是空的
        if (q1.empty())
            q2.push(x);
        else
            q1.push(x);

    }

    int pop() {//在需要pop的时候将非空队列的前n个值转换到空队列中，然后pop非空队列
        if (q2.empty())
        {
            swap(q1, q2);
        }
        int size = q2.size();
        for (size_t i = 0; i < size - 1; ++i)//此时q1为空，q2有值
        {
            q1.push(q2.front());
            q2.pop();
        }
        int ret = q2.front();
        q2.pop();
        return ret;
    }

    int top() {//非空队列中的最后一个元素即是栈顶元素
        if (q1.empty())
        {
            return q2.back();
        }
        else
            return q1.back();
    }

    bool empty() {
        return q1.empty() && q2.empty();
    }
};

int main()
{
    MyStack st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout << st.pop() << endl;
    cout << st.pop() << endl;
    cout << st.pop() << endl;
    cout << st.empty() << endl;
    return 0;
}

