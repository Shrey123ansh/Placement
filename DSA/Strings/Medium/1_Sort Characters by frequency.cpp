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