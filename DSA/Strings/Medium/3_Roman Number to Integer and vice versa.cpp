Example 1:

Input: s = "III"
Output: 3
Explanation: III = 3.
Example 2:

Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.
Example 3:

Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

int romanToInt(string s)
{
    unordered_map<char, int> m;

    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;

    int ans = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (m[s[i]] < m[s[i + 1]])
        {
            ans -= m[s[i]];
        }
        else
        {
            ans += m[s[i]];
        }
    }
    return ans;
}
