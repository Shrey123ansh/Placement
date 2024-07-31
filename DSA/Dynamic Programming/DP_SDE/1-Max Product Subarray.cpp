// https://takeuforward.org/data-structure/maximum-product-subarray-in-an-array/


Example 1:
Input:
 Nums = [1,2,3,4,5,0]
Output: 120
Explanation:
 In the given array, we can see 1×2×3×4×5 gives maximum product value.
Example 2:
Input:
 Nums = [1,2,-3,0,-4,-5]
Output: 20
Explanation:
 In the given array, we can see (-4)×(-5) gives maximum product value.

int maxProductSubArray(vector<int> &nums)
{
    int result = INT_MIN;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            int prod = 1;
            for (int k = i; k <= j; k++)
                prod *= nums[k];
            result = max(result, prod);
        }
    }
    return result;
}

int maxProductSubArray(vector<int> &nums)
{
    int result = nums[0];
    for (int i = 0; i < nums.size() - 1; i++)
    {
        int p = nums[i];
        for (int j = i + 1; j < nums.size(); j++)
        {
            result = max(result, p);
            p *= nums[j];
        }
        result = max(result, p); // manages (n-1)th term
    }
    return result;
}

int maxProductSubArray(vector<int> &arr)
{
    int n = arr.size(); // size of array.

    int pre = 1, suff = 1;
    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (pre == 0)
            pre = 1;
        if (suff == 0)
            suff = 1;
        pre *= arr[i];
        suff *= arr[n - i - 1];
        ans = max(ans, max(pre, suff));
    }
    return ans;
}

int maxProductSubArray(vector<int> &nums)
{
    int prod1 = nums[0], prod2 = nums[0], result = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
        int temp = max({nums[i], prod1 * nums[i], prod2 * nums[i]});
        prod2 = min({nums[i], prod1 * nums[i], prod2 * nums[i]});
        prod1 = temp;

        result = max(result, prod1);
    }

    return result;
}