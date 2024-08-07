int countDigits(int n)
{
    // Initialize a counter variable
    // 'cnt' to store the count of digits.
    int cnt = 0;
    // While loop iterates until 'n'
    // becomes 0 (no more digits left).
    while (n > 0)
    {
        // Increment the counter
        // for each digit encountered.
        cnt = cnt + 1;
        // Divide 'n' by 10 to
        // remove the last digit.
        n = n / 10;
    }
    // Return the
    // count of digits.
    return cnt;
}

int countDigits(int n)
{
    // Initialize a variable 'cnt' to
    // store the count of digits.
    int cnt = (int)(log10(n) + 1);

    // The expression (int)(log10(n)+1)
    // calculates the number of digits in 'n'
    // and casts it to an integer.

    // Adding 1 to the result accounts
    // for the case when 'n' is a power of 10,
    // ensuring that the count is correct.

    // Finally, the result is cast
    // to an integer to ensure it is rounded
    // down to the nearest whole number.

    // Return the count of digits in 'n'.
    return cnt;
}