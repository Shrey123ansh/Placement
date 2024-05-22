int singleNumber(vector<int> &nums)
{
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        ans = ans ^ nums[i];
    }
    return ans;
}

int singleNumber(vector<int> &nums)
{
    unordered_map<int, int> a;
    for (auto x : nums)
        a[x]++;
    for (auto z : a)
        if (z.second == 1)
            return z.first;
    return -1;
}