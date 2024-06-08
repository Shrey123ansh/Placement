int maxDepth(string s)
{
    int maxi = INT_MIN;
    int count = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            count++;
        else if (s[i] == ')')
        {
            maxi = max(count, maxi);
            count--;
        }
    }

    return (maxi > 0) ? maxi : 0;
}