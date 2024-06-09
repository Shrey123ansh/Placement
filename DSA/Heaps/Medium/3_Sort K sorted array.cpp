vector<int> mergeKArrays(vector<vector<int>> arr, int K)
{
    // code here
    vector<int> ans;
    priority_queue<int, vector<int>, greater<int>> vq;

    for (int i = 0; i < K; i++)
    {
        for (int j = 0; j < K; j++)
        {
            vq.push(arr[i][j]);
        }
    }

    while (vq.size() > 0)
    {
        ans.push_back(vq.top());
        vq.pop();
    }
    return ans;
}