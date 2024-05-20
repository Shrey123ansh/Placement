int maxSubArray(vector<int> &nums)
{
    int maxi = INT_MIN; // maximum sum

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i; j < nums.size(); j++)
        {
            // subarray = arr[i.....j]
            int sum = 0;

            // add all the elements of subarray:
            for (int k = i; k <= j; k++)
            {
                sum += nums[k];
            }

            maxi = max(maxi, sum);
        }
    }

    return maxi;
}

int maxSubArray(vector<int> &nums)
{
    int maxi = INT_MIN; // maximum sum

    for (int i = 0; i < nums.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < nums.size(); j++)
        {
            sum += nums[j];
            maxi = max(maxi, sum);
        }
    }

    return maxi;
}

int maxSubArray(vector<int> &nums)
{
    int maxi = INT_MIN; // maximum sum

    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        maxi = max(maxi, sum);
        if (sum < 0)
            sum = 0;
    }

    return maxi;
}