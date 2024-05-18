int fl(int arr[], int n, int x)
{
    int low = 0;
    int high = n - 1;
    int mid = low + (high - low) / 2;
    int ans = -1;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (arr[mid] <= x)

        {
            ans = arr[mid];
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}
int cl(int arr[], int n, int x)
{
    int low = 0;
    int high = n - 1;
    int mid = low + (high - low) / 2;
    int ans = -1;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (arr[mid] >= x)

        {
            ans = arr[mid];
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

pair<int, int> getFloorAndCeil(int arr[], int n, int x)
{
    sort(arr, arr + n);
    int f = fl(arr, n, x);
    int c = cl(arr, n, x);
    return {f, c};
}