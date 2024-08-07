Example 1:

Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 
Example 2:

Input: s = "aaacb"
Output: 3
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 
Example 3:

Input: s = "abc"
Output: 1


int numberOfSubstrings(string s)
{
    int n = size(s);

    int i = 0, j = 0, count = 0;

    unordered_map<char, int> mp;

    while (j < n)
    {
        mp[s[j]]++;

        while (mp['a'] >= 1 && mp['b'] >= 1 && mp['c'] >= 1)
        {
            count += (n - j);

            // shrinking the window
            mp[s[i]]--;
            i++;
        }
        j++;
    }
    return count;
}
