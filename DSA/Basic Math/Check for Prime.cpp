bool checkPrime(int n)
{
    // Initialize a counter variable to
    // count the number of factors.
    int cnt = 0;
    // Loop through numbers from 1 to n.
    for (int i = 1; i <= n; i++)
    {
        // If n is divisible by i
        // without any remainder.
        if (n % i == 0)
        {
            // Increment the counter.
            cnt = cnt + 1;
        }
    }

    // If the number of
    // factors is exactly 2
    if (cnt == 2)
    {
        // Return true, indicating
        // that the number is prime.
        return true;
    }
    // If the number of
    // factors is not 2.
    else
    {
        // Return false, indicating
        // that the number is not prime.
        return false;
    }
}