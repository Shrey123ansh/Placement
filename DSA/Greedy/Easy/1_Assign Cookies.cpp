int findContentChildren(vector<int> &childrens, vector<int> &cookies)
{
    int n = childrens.size(), i = 0;
    int m = cookies.size(), j = 0;
    int ans = 0;

    sort(childrens.begin(), childrens.end());
    sort(cookies.begin(), cookies.end());

    while (i < n && j < m)
    {
        if (childrens[i] <= cookies[j])
        {
            ans++;
            i++;
            j++;
        }
        else
            j++;
    }
    return ans;
}