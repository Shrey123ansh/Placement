
int *printDivisors(int n, int &size)
{
    // Allocate memory for
    // the array of divisors
    int *divisors = new int[n];
    // Initialize the count of divisors
    int count = 0;

    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            // Add the divisor to the array
            divisors[count++] = i;
        }
    }
    // Update the size parameter
    // with the count of divisors
    size = count;
    // Return the array of divisors
    return divisors;
}