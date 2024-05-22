int dtb(int n)
{
    int cnt = 0;
    while (n > 0)
    {
        int rem = n % 2;
        if (rem == 1)
        {
            cnt++;
        }
        n = n >> 1;
    }
    cout << cnt << endl;
    return cnt;
}
int minBitFlips(int start, int goal)
{
    int decimal = start ^ goal;
    int a = dtb(decimal);
    return a;
}