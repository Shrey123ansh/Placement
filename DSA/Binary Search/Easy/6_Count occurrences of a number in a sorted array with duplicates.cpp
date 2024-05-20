int lower_bound(int arr[], int low, int high, int target)
{
    while (low <= high)
    {
        int mid = low + ((high - low) / 2);
        if (arr[mid] >= target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}

int count(int arr[], int n, int x)
{
    // code here
    int left = 0, right = n - 1;
    int lb = lower_bound(arr, left, right, x);
    int ub = lower_bound(arr, left, right, x + 1) - 1;
    if (lb < n && arr[lb] == x)
    {
        return (ub - lb) + 1;
    }
    else
    {
        return 0;
    }
}