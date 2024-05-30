int findPeakElement(vector<int> &nums)
{
    int n = nums.size(); // Size of array.

    for (int i = 0; i < n; i++)
    {
        // Checking for the peak:
        if ((i == 0 || nums[i - 1] < nums[i]) && (i == n - 1 || nums[i] > nums[i + 1]))
        {
            return i;
        }
    }
    // Dummy return statement
    return -1;
}

int findPeakElement(vector<int> &nums)
{
    int n = nums.size(); // Size of array.

    // Edge cases:
    if (n == 1)
        return 0;
    if (nums[0] > nums[1])
        return 0;
    if (nums[n - 1] > nums[n - 2])
        return n - 1;

    int low = 1, high = n - 2;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        // If arr[mid] is the peak:
        if (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1])
            return mid;

        // If we are in the left:
        if (nums[mid] > nums[mid - 1])
            low = mid + 1;

        // If we are in the right:
        // Or, arr[mid] is a common point:
        else
            high = mid - 1;
    }
    // Dummy return statement
    return -1;
}