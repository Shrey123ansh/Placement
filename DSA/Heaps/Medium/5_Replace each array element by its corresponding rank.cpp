vector<int> replaceWithRank(vector<int> &arr, int N)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int i = 0; i < N; i++)
    {
        pq.push({arr[i], i});
    }

    int cnt = 1;
    vector<int> ans(N);
    while (!pq.empty())
    {
        int ind = pq.top().second;
        int a = pq.top().first;
        pq.pop();
        ans[ind] = cnt;
        if (a != pq.top().first)
        {
            cnt++;
        }
    }

    return ans;
}