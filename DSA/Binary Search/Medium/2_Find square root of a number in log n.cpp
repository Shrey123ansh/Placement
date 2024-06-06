long long int floorSqrt(long long int x)
{
    // Your code goes here
    int ans = 0;

    for (int i = 1; i <= x; i++)
    {
        if (i * i <= x)
        {
            ans = i;
        }
        else
        {
            break;
        }
    }
    return ans;
}

long long int floorSqrt(long long int x)
{
    // Your code goes here
    int ans = sqrt(x);
    return ans;
}

long long int floorSqrt(long long int x)
{
    // Your code goes here
    int low = 1, high = x;

    while (low <= high)
    {
        long long mid = (low + high) / 2;
        long long val = mid * mid;

        if (val <= x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return high;
}