// Example 1:
// Input: s = "tree"
// Output: "eert"
// Explanation: 'e' appears twice while 'r' and 't' both appear once.
// So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

// Example 2:
// Input: s = "cccaaa"
// Output: "aaaccc"
// Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
// Note that "cacaca" is incorrect, as the same characters must be together.
string frequencySort(string s)
{
    map<char, int> mp;
    for (auto it : s)
    {
        mp[it]++;
    }
    priority_queue<pair<int, char>> pq;
    for (auto it : mp)
    {
        pq.push({it.second, it.first});
    }

    string om = "";
    while (!pq.empty())
    {
        int n = pq.top().first;
        char ch = pq.top().second;
        pq.pop();

        for (int i = 0; i < n; i++)
        {
            om += ch;
        }
    }
    return om;
}
