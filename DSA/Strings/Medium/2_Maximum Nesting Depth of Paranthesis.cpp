// Example 1:

// Input: s = "(1+(2*3)+((8)/4))+1"

// Output: 3

// Explanation:

// Digit 8 is inside of 3 nested parentheses in the string.

// Example 2:

// Input: s = "(1)+((2))+(((3)))"

// Output: 3

// Explanation:

// Digit 3 is inside of 3 nested parentheses in the string.
int maxDepth(string s)
{
    int maxi = INT_MIN;
    int count = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            count++;
        else if (s[i] == ')')
        {
            maxi = max(count, maxi);
            count--;
        }
    }

    return (maxi > 0) ? maxi : 0;
}
