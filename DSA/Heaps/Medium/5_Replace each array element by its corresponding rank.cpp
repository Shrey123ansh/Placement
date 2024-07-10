Input:
N = 6
arr = [20, 15, 26, 2, 98, 6]
Output:
4, 3, 5, 1, 6, 2
Explanation:
After sorting, array becomes {2,6,15,20,26,98}
Rank(2) = 1 (at index 0) 
Rank(6) = 2 (at index 1) 
Rank(15) = 3 (at index 2) 
Rank(20) = 4 (at index 3) and so on..
    
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
