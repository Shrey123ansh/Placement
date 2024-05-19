class MyQueue
{
    stack<int> s1;
    stack<int> s2;

public:
    MyQueue()
    {
    }

    void push(int x)
    {
        s1.push(x);
    }

    int pop()
    {
        int temp;
        while (!s1.empty())
        {
            temp = s1.top();
            s2.push(temp);
            s1.pop();
        }
        s2.pop();
        int last = temp;
        while (!s2.empty())
        {
            temp = s2.top();
            s2.pop();
            s1.push(temp);
        }
        return last;
    }

    int peek()
    {
        int temp;
        while (!s1.empty())
        {
            temp = s1.top();
            s2.push(temp);
            s1.pop();
        }
        int last = temp;
        while (!s2.empty())
        {
            temp = s2.top();
            s2.pop();
            s1.push(temp);
        }
        return last;
    }

    bool empty()
    {
        return s1.empty();
    }
};