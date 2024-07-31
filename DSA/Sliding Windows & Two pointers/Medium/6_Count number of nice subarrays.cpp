Example 1:

Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
Example 2:

Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There are no odd numbers in the array.

    
int subarray(vector<int> &nums, int k)
{
    if (k < 0)
        return 0;

    int l = 0, r = 0, odd = 0, count = 0;

    while (r < nums.size())
    {
        if (nums[r] % 2)
            odd++;

        while (odd > k)
        {
            if (nums[l] % 2)
                odd--;

            l++;
        }

        count = count + (r - l + 1);

        r++;
    }

    return count;
}

int numberOfSubarrays(vector<int> &nums, int k)
{

    return subarray(nums, k) - subarray(nums, k - 1);
}
