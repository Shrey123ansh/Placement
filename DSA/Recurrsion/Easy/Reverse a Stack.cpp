void Reverse(stack<int> &St)
{
    if (St.empty())
    {
        return;
    }

    int temp = St.top();
    St.pop();
    Reverse(St);
    insertAtbottom(St, temp);
}

void insertAtbottom(stack<int> &s, int temp)
{
    if (s.empty())
    {
        s.push(temp);
        return;
    }

    int x = s.top();
    s.pop();
    insertAtbottom(s, temp);
    s.push(x);
}