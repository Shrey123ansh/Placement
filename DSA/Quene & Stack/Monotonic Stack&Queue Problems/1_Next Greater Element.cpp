Example 1:

Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
- 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
- 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.


vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
{
    unordered_map<int, int> mp;
    stack<int> st;

    for (int i = nums2.size() - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= nums2[i])
        {
            st.top();
        }
        mp[nums2[i]] = st.empty() ? -1 : st.top();
        st.push(nums2[i]);
    }

    vector<int> ans;
    for (auto num : nums1)
    {
        ans.push_back(mp[num]);
    }

    return ans;
}