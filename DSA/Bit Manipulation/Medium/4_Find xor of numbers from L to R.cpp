int findXOR(int l, int r)
{
    // complete the function here
    return (fun(l - 1) ^ fun(r));
}

int fun(int x)
{
    if (x % 4 == 0)
        return (x);
    if (x % 4 == 1)
        return (1);
    if (x % 4 == 2)
        return (x + 1);
    return (0);
}