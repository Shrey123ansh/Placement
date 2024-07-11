Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.

string minWindow(string s, string t)
{
    unordered_map<char, int> mp;
    for (auto it : t)
    {
        mp[it]++;
    }
    int r = 0;
    int l = 0;
    int count = 0;
    int sindex = -1;
    int mini = INT_MAX;
    while (r < s.size())
    {
        if (mp[s[r]] > 0)
            count++;
        mp[s[r]]--;
        while (count == t.length())
        {
            if (r - l + 1 < mini)
            {
                mini = r - l + 1, mini;
                sindex = l;
            }

            mp[s[l]]++;
            if (mp[s[l]] > 0)
                count--;
            l++;
        }
        r++;
    }
    return sindex == -1 ? "" : s.substr(sindex, mini);
}