Example 1:

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
Example 2:

Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

int longestOnes(vector<int> &nums, int k)
{
    int i = 0, j = 0;
    int ans = 0, cost = 0, n = nums.size();
    while (j < n)
    {
        if (nums[j++] == 0)
            cost++;
        while (cost > k)
            if (nums[i++] == 0)
                cost--;
        ans = max(ans, j - i);
    }
    return ans;
}
