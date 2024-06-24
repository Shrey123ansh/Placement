bool isPossible(int a, int b)
{
    // code here
    if (a == 2 && b == 3 || a == 3 && b == 2)
    {
        return 1;
    }
    if (a == 1 && b == 2 || a == 2 && b == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

bool isPossible(int a, int b)
{
    // code here
    return a == 2 ^ b == 2;
}

bool isPossible(int a, int b)
{
    // code here
    return (a + b) % 2
}