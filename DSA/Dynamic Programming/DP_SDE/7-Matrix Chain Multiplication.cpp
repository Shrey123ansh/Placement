// https://takeuforward.org/dynamic-programming/matrix-chain-multiplication-dp-48/
Example 1:
Input: N = 5
arr = {40, 20, 30, 10, 30}
Output: 26000
Explanation: There are 4 matrices of dimension 
40x20, 20x30, 30x10, 10x30. Say the matrices are 
named as A, B, C, D. Out of all possible combinations,
the most efficient way is (A*(B*C))*D. 
The number of operations are -
20*30*10 + 40*20*10 + 40*10*30 = 26000.

Example 2:
Input: N = 4
arr = {10, 30, 5, 60}
Output: 4500
Explanation: The matrices have dimensions 
10*30, 30*5, 5*60. Say the matrices are A, B 
and C. Out of all possible combinations,the
most efficient way is (A*B)*C. The 
number of multiplications are -
10*30*5 + 10*5*60 = 4500.

int f(vector<int> &arr, int i, int j)
{

    // base condition
    if (i == j)
        return 0;

    int mini = INT_MAX;

    // partioning loop
    for (int k = i; k <= j - 1; k++)
    {

        int ans = f(arr, i, k) + f(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];

        mini = min(mini, ans);
    }

    return mini;
}

int matrixMultiplication(vector<int> &arr, int N)
{

    int i = 1;
    int j = N - 1;

    return f(arr, i, j);
}

/// or//////////

int f(vector<int> &arr, int i, int j, vector<vector<int>> &dp)
{

    // base condition
    if (i == j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int mini = INT_MAX;

    // partioning loop
    for (int k = i; k <= j - 1; k++)
    {

        int ans = f(arr, i, k, dp) + f(arr, k + 1, j, dp) + arr[i - 1] * arr[k] * arr[j];

        mini = min(mini, ans);
    }

    return mini;
}

int matrixMultiplication(vector<int> &arr, int N)
{

    vector<vector<int>> dp(N, vector<int>(N, -1));

    int i = 1;
    int j = N - 1;

    return f(arr, i, j, dp);
}
