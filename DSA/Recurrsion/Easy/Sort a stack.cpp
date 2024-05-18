void insert(stack<int> &s, int temp)
{
    if (s.empty() || temp >= s.top())
    {
        s.push(temp);
        return;
    }

    int x = s.top();
    s.pop();
    insert(s, temp);
    s.push(x);
}

void solve(stack<int> &s)
{
    if (s.size() == 1)
    {
        return;
    }

    int temp = s.top();
    s.pop();
    solve(s);
    insert(s, temp);
}

void SortedStack ::sort()
{
    // Your code here
    solve(this->s);
}