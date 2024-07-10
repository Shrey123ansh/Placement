Example 1 :

    Input : g = [ 1, 2, 3 ],
            s = [ 1, 1 ] Output : 1 Explanation : You have 3 children and 2 cookies.The greed factors of 3 children are 1, 2, 3. And even though you have 2 cookies, since their size is both 1, you could only make the child whose greed factor is 1 content.You need to output 1. Example 2 :

    Input : g = [ 1, 2 ],
            s = [ 1, 2, 3 ] Output : 2 Explanation : You have 2 children and 3 cookies.The greed factors of 2 children are 1, 2. You have 3 cookies and their sizes are big enough to gratify all of the children,
            You need to output 2.

    int
    findContentChildren(vector<int> &childrens, vector<int> &cookies)
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
