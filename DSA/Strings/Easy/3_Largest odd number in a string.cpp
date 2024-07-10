// Example 1:

// Input: num = "52"
// Output: "5"
// Explanation: The only non-empty substrings are "5", "2", and "52". "5" is the only odd number.
// Example 2:

// Input: num = "4206"
// Output: ""
// Explanation: There are no odd numbers in "4206".
string largestOddNumber(string num)
{
    int n = num.length();
    for (int s = n - 1; s >= 0; s--)
    {
        int val = num[s] - '0';
        if (val % 2 == 0)
            num.pop_back();
        else
            return num;
    }
    return "";
}
