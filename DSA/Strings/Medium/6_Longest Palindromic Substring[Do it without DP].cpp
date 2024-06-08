bool solve(string &s, int i, int j)
{
    while (i < j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

string longestPalindrome(string s)
{
    if (s.size() <= 1)
        return s;
    int max = 1, n = s.size();
    string ans = "";
    ans.push_back(s[0]);
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (solve(s, i, j) && j - i + 1 > max)
            {
                max = j - i + 1;
                ans = s.substr(i, max);
            }
        }
    }
    return ans;
}