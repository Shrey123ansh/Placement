vector<int> findPrimeFactors(int N)
{
    vector<int> sett;
    for (int i = 2; i <= N; i++)
    {
        if (N % i == 0)
        {
            while (N % i == 0)
            {
                sett.push_back(i);
                N = N / i;
            }
        }
    }
    return sett;
}

vector<int> findPrimeFactors(int n)
{

    // Write your code here
    vector<int> ans;
    for (int i = 2; i * i <= n or n > 1; i++)
    {
        if (n % i == 0)
        {
            while (n > 0 and n % i == 0)
            {
                ans.push_back(i);
                n /= i;
            }
        }
    }
    return ans;
}