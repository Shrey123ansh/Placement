int d(vector<int> &dp, vector<int> &height, int i)
{
    if (i < 1)
    {
        return 0;
    }
    if (dp[i] != -1)
    {
        return dp[i];
    }
    int right = INT_MAX;
    int left = d(dp, height, i - 1) + abs(height[i] - height[i - 1]);
    if (i > 1)
    {
        right = d(dp, height, i - 2) + abs(height[i] - height[i - 2]);
    }
    dp[i] = min(left, right);
    return dp[i];
}
int minimumEnergy(vector<int> &height, int n)
{
    vector<int> dp(n + 1, -1);
    return d(dp, height, n - 1);
}

/////////////////OR//////////////

int minimumEnergy(vector<int> &height, int n)
{
    // Code here

    vector<int> dp(n, -1);

    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {

        int fs = dp[i - 1] + abs(height[i] - height[i - 1]);
        int ss = INT_MAX;
        if (i > 1)
            ss = dp[i - 2] + abs(height[i] - height[i - 2]);

        dp[i] = min(fs, ss);
    }

    return dp[n - 1];
}

/////////////////OR//////////////

int minimumEnergy(vector<int> &height, int n)
{
    int prev = 0;
    int prev2 = 0;
    for (int i = 1; i < n; i++)
    {

        int jumpTwo = INT_MAX;
        int jumpOne = prev + abs(height[i] - height[i - 1]);
        if (i > 1)
            jumpTwo = prev2 + abs(height[i] - height[i - 2]);

        int cur_i = min(jumpOne, jumpTwo);
        prev2 = prev;
        prev = cur_i;
    }
    return prev;
}