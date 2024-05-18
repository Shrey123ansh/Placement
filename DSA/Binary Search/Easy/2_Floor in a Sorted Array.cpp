int findFloor(vector<long long> v, long long n, long long x)
{

    // Your code here
    long long low = 0;
    long long high = n - 1;
    long long mid = low + (high - low) / 2;
    long long ans = -1;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (v[mid] == x) // If current ele is equal to x, then it is the floor of x
        {
            return mid;
        }
        else if (v[mid] < x)

        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}