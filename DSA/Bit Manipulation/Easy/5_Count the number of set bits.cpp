int countSetBits(int n)
{
    // Your logic here
    int count = 0;
    while (n)
    {
        count += getcount(n);
        n--;
    }

    return count;
}

int getcount(int n)
{
    int count = 0;
    while (n)
    {
        count++;
        n = n & (n - 1);
    }
    return count;
}