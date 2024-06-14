
int numSubarraysWithSum(vector<int> &nums, int goal)
{
    int res = 0;
    for (int start = 0; start < nums.size(); ++start)
    {
        int sum = 0;
        for (int end = start; end < nums.size(); ++end)
        {
            sum += nums[end];
            if (sum == goal)
                ++res;
        }
    }
    return res;
}

///////////////////////OR//////////////////////////

int numSubarraysWithSum(vector<int> &nums, int goal)
{

    return atMost(nums, goal) - atMost(nums, goal - 1);
}

int atMost(vector<int> &nums, int goal)
{
    if (goal < 0)
        return 0;
    int count = 0, sum = 0;
    int l = 0, r = 0;
    while (r < nums.size())
    {
        sum += nums[r];
        while (sum > goal)
        {
            sum -= nums[l++];
        }
        count += r - l + 1;
        ++r;
    }
    return count;
}
///////////////////////OR//////////////////////////

int numSubarraysWithSum(vector<int> &nums, int goal)
{
    map<int, int> mp;
    int ans = 0, sum = 0;
    mp[0] = 1;
    for (auto i : nums)
    {
        sum += i;
        ans += mp[sum - goal];
        mp[sum]++;
    }
    return ans;
}
