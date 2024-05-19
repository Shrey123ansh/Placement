vector<long long> factorialNumbers(long long n)
{
    // Write Your Code here
    long long int fact = 1;
    vector<long long int> v;
    for (long long int i = 2; fact <= n; i++)
    {
        v.push_back(fact);
        fact = fact * i;
    }
    return v;
}