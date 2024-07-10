Example 1:

Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
Example 2:

Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.
Example 3:

Input: intervals = [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
    
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
