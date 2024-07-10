Example 1:

Input: nums = [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number. 
The second 1's next greater number needs to search circularly, which is also 2.
Example 2:

Input: nums = [1,2,3,4,3]
Output: [2,3,4,-1,4]

vector<int> nextGreaterElements(vector<int> &nums)
{
    int n = nums.size();
    vector<int> nge(n, -1);
    stack<int> st;
    for (int i = 2 * n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= nums[i % n])
        {
            st.pop();
        }

        if (i < n)
        {
            if (!st.empty())
                nge[i] = st.top();
        }
        st.push(nums[i % n]);
    }
    return nge;
}