int func(int mid, int n, int m)
{
    long long ans = 1;

    for (int i = 1; i <= n; i++)
    {
        ans = ans * mid;
        if (ans > m)
            return 2;
    }
    if (ans == m)
        return 1;

    return 0;
}

int NthRoot(int n, int m)
{
    // Code here.
    int start = 1, end = m;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        int midN = func(mid, n, m);
        if (midN == 1)
        {
            return mid;
        }
        else if (midN == 0)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}