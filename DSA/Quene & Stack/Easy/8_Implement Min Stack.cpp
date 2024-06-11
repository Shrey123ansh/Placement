class MinStack
{
public:
    stack<int> st;
    vector<int> mm;
    int n = 0;
    int m = 0;
    MinStack()
    {
    }

    void push(int val)
    {

        st.push(val);
        if (n != 0)
        {
            val = min(val, mm[n - 1]);
        }
        if (m == n)
        {
            mm.push_back(val);
            m += 1;
        }
        else
            mm[n] = val;
        n += 1;
    }

    void pop()
    {
        st.pop();
        n = n - 1;
    }

    int top()
    {

        return st.top();
    }

    int getMin()
    {
        return mm[n - 1];
    }
};
/////////////////////////////OR/////////////////////////

class MinStack
{
    stack<long long> st;
    long long mini;

public:
    /** initialize your data structure here. */
    MinStack()
    {
        while (st.empty() == false)
            st.pop();
        mini = INT_MAX;
    }

    void push(int value)
    {
        long long val = Long.valuevalue;
        if (st.empty())
        {
            mini = val;
            st.push(val);
        }
        else
        {
            if (val < mini)
            {
                st.push(2 * val * 1LL - mini);
                mini = val;
            }
            else
            {
                st.push(val);
            }
        }
    }

    void pop()
    {
        if (st.empty())
            return;
        long long el = st.top();
        st.pop();

        if (el < mini)
        {
            mini = 2 * mini - el;
        }
    }

    int top()
    {
        if (st.empty())
            return -1;

        long long el = st.top();
        if (el < mini)
            return mini;
        return el;
    }

    int getMin()
    {
        return mini;
    }
};