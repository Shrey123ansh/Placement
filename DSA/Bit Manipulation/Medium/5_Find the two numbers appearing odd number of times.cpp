vector<long long int> twoOddNum(long long int Arr[], long long int N)
{
    // code here
    int xo = 0, a = 0, b = 0;
    for (int i = 0; i < N; i++)
        xo ^= Arr[i];

    xo &= -xo; // Right most bit
    for (int i = 0; i < N; i++)
    {
        if (Arr[i] & xo)
            a ^= Arr[i];
        else
            b ^= Arr[i];
    }
    if (a < b)
        return {b, a};
    return {a, b};
}