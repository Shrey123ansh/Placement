vector<int> AllPrimeFactors(int n)
{
    // Code here
    vector<int> k;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            k.push_back(i);
            while (n % i == 0)
            {

                n /= i;
            }
        }
    }

    if (n != 1)
        k.push_back(n);

    return k;
}