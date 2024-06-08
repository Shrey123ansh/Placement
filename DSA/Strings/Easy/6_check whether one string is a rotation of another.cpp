bool rotateString(string s, string goal)
{
    if (s.size() != goal.size())
    {
        return false;
    }
    for (int i = 0; i < s.size(); i++)
    {
        s = s.substr(1, s.size()) + s.substr(0, 1);
        if (s == goal)
        {
            return true;
        }
    }
    return false;
}

bool rotateString(string s, string goal)
{
    if (s.size() != goal.size())
    {
        return false;
    }
    int n = s.size();
    char temp;
    for (int i = 0; i < n; i++)
    {
        temp = goal[0];
        for (int j = 0; j < n - 1; j++)
        {
            goal[j] = goal[j + 1];
        }
        goal[n - 1] = temp;
        if (s == goal)
        {
            return true;
        }
    }
    return false;
}