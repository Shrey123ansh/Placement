Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [2,3,0,1,4]
Output: 2
    
    int findPlatform(int arr[], int dep[], int n)
{
    // Your code here
    int ans = 1; // final value
    for (int i = 0; i <= n - 1; i++)
    {
        int count = 1; // count of overlapping interval of only this   iteration
        for (int j = i + 1; j <= n - 1; j++)
        {
            if ((arr[i] >= arr[j] && arr[i] <= dep[j]) ||
                (arr[j] >= arr[i] && arr[j] <= dep[i]))
            {
                count++;
            }
        }
        ans = max(ans, count); // updating the value
    }
    return ans;
}

////////////////////OR///////////////////////

int findPlatform(int arr[], int dep[], int n)
{
    // Your code here
    sort(arr, arr + n);
    sort(dep, dep + n);

    int ans = 1;
    int count = 1;
    int i = 1, j = 0;
    while (i < n && j < n)
    {
        if (arr[i] <= dep[j]) // one more platform needed
        {
            count++;
            i++;
        }
        else // one platform can be reduced
        {
            count--;
            j++;
        }
        ans = max(ans, count); // updating the value with the current maximum
    }
    return ans;
}
