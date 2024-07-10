Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
    
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    vector<vector<int>> result;
    int i = 0;
    int n = intervals.size();

    // Step 1: Add all intervals that end before the new interval starts
    // Example: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
    // Add intervals ending before 4: [[1,2]]
    while (i < n && intervals[i][1] < newInterval[0])
    {
        result.push_back(intervals[i]);
        i++;
    }
    // At this point, result = [[1,2]], i = 1

    // Step 2: Merge all overlapping intervals with the new interval
    // Intervals that overlap with [4,8]: [[3,5],[6,7],[8,10]]
    // Merge process:
    // 1. Merge [3,5]  with [4,8] -> [3,8]
    // 2. Merge [6,7]  with [3,8] -> [3,8]
    // 3. Merge [8,10] with [3,8] -> [3,10]
    // MERGE UNTIL `newInterval` (updated) "end" is "more" than than start of intervels[i]
    while (i < n && intervals[i][0] <= newInterval[1])
    {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }
    // At this point, newInterval = [3,10], i = 4

    // Step 3: Add the merged interval
    // Add the merged newInterval: [3,10] to the result
    result.push_back(newInterval);
    // At this point, result = [[1,2], [3,10]]

    // Step 4: Add all intervals that start after the new interval ends
    // Add remaining intervals: [[12,16]]
    while (i < n)
    {
        result.push_back(intervals[i]);
        i++;
    }
    // At this point, result = [[1,2], [3,10], [12,16]]

    return result;
}
