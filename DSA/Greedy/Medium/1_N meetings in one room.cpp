Input: n = 6, start[] = {1,3,0,5,8,5}, end[] =  {2,4,6,7,9,9}
Output: 4
Explanation: Maximum four meetings can be held with given start and end timings. The meetings are - (1, 2),(3, 4), (5,7) and (8,9)
Input: n = 3, start[] = {10, 12, 20}, end[] = {20, 25, 30}
Output: 1
Explanation: Only one meetings can be held with given start and end timings.

struct meeting
{
    int start;
    int end;
    int pos;
};
// Function to find the maximum number of meetings that can
// be performed in a meeting room.
static bool comparator(struct meeting m1, struct meeting m2)
{
    if (m1.end < m2.end)
        return true;
    else if (m1.end > m2.end)
        return false;
    else if (m1.start < m2.start)
        return true;
    else
        return false;
}

int maxMeetings(int s[], int e[], int n)
{
    // Your code here
    struct meeting meet[n];
    for (int i = 0; i < n; i++)
    {
        meet[i].start = s[i], meet[i].end = e[i], meet[i].pos = i + 1;
    }

    sort(meet, meet + n, comparator);

    vector<int> answer;

    int limit = meet[0].end;
    answer.push_back(meet[0].pos);

    for (int i = 1; i < n; i++)
    {
        if (meet[i].start > limit)
        {
            limit = meet[i].end;
            answer.push_back(meet[i].pos);
        }
    }

    return answer.size();
}
