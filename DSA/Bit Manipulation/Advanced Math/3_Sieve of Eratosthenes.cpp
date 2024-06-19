int countPrimes(int n)
{
    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;
    int c = 0;
    for (int i = 2; i < n; i++)
    {
        if (prime[i])
        {
            c++;
            for (int j = 2 * i; j < n; j = j + i)
            {
                prime[j] = 0;
            }
        }
    }
    return c;
}

int countPrimes(int n)
{
    if (n <= 1)
        return 0;

    vector<bool> primes(n + 1, 1);
    primes[0] = primes[1] = 0;
    int cnt = 1;

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (primes[i])
        {
            for (int j = i * i; j < n; j += i)
            {
                if (primes[j])
                    cnt++;
                primes[j] = 0;
            }
        }
    }

    return n - cnt - 1;
}
