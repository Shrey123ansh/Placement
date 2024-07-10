Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [2,3,0,1,4]
Output: 2
    
    int jump(vector<int> &nums)
{
    if (nums.size() <= 1)
        return 0;
    int maxreach = 0, curreach = 0;
    int jumps = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        maxreach = max(maxreach, nums[i] + i);
        if (i >= curreach)
        {
            jumps++;
            curreach = maxreach;
        }
        if (curreach >= nums.size() - 1)
            break;
    }
    return jumps;
}
