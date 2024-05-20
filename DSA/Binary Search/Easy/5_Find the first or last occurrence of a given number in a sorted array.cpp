vector<int> searchRange(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<int> res = {-1, -1};
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == target)
        {
            res[0] = i;
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (nums[i] == target)
        {
            res[1] = i;
            break;
        }
    }
    return res;
}

//////////////////////////////////OR/////////////////////////////////

int lower_bound(vector<int> &nums, int low, int high, int target)
{
    while (low <= high)
    {
        int mid = low + ((high - low) / 2);
        if (nums[mid] >= target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}

vector<int> searchRange(vector<int> &nums, int target)
{
    int n = nums.size();
    int left = 0, right = n - 1;
    int lb = lower_bound(nums, left, right, target);
    int ub = lower_bound(nums, left, right, target + 1) - 1;
    if (lb < n && nums[lb] == target)
    {
        return {lb, ub};
    }
    else
    {
        return {-1, -1};
    }
}