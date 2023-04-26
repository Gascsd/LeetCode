#include <iostream>
#include <queue>
using namespace std;


class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    MyStack() {

    }

    void push(int x) {//�����ڽṹ�ϱ�֤������һ�������ǿյ�
        if (q1.empty())
            q2.push(x);
        else
            q1.push(x);

    }

    int pop() {//����Ҫpop��ʱ�򽫷ǿն��е�ǰn��ֵת�����ն����У�Ȼ��pop�ǿն���
        if (q2.empty())
        {
            swap(q1, q2);
        }
        int size = q2.size();
        for (size_t i = 0; i < size - 1; ++i)//��ʱq1Ϊ�գ�q2��ֵ
        {
            q1.push(q2.front());
            q2.pop();
        }
        int ret = q2.front();
        q2.pop();
        return ret;
    }

    int top() {//�ǿն����е����һ��Ԫ�ؼ���ջ��Ԫ��
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

