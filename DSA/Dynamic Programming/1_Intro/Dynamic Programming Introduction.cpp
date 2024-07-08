long long int f1(int n, vector<long long int> &dp)
{
    if (n <= 1)
    {
        return n;
    }
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = f1(n - 1, dp) + f1(n - 2, dp);
}
long long int topDown(int n)
{
    // code here
    vector<long long int> dp(n + 1, -1);
    return f1(n, dp);
}
long long int bottomUp(int n)
{
    // code here

    vector<long long int> dp(n + 1, 0);

    if (n <= 1)
        return n;
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}