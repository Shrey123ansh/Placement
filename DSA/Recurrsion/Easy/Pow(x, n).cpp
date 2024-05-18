double myPow(double x, int n)
{
    double ans = 0;
    ans = calc_pow(x, n);
    return ans;
}

double calc_pow(double x, int n)
{
    if (n == 0)
        return 1;
    else if (n > 0)
        return x * calc_pow(x, n - 1);
    else
        return 1 / x * calc_pow(x, n + 1);
}