int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
    int ans = 0, end = -1e5;
    sort(intervals.begin(), intervals.end());

    for (auto &child : intervals)
        if (end > child[0])
        {
            ans++;
            end = min(end, child[1]);
        }
        else
            end = child[1];

    return ans;
}