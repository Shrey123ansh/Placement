// Input:  arr     = [3, 4, 2, 7, 5, 8, 10, 6]
//         queries = 2
//         indices = [0, 5]
// Output:  6, 1
// Explanation:
// The next greater elements to the right of 3(index 0)
// are 4,7,5,8,10,6.
// The next greater elements to the right of 8(index 5)
// is only 10.

vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices)
{
    // write your code here
    vector<int> ans(queries);
    for (int i = 0; i < queries; i++)
    {
        int curr = arr[indices[i]];
        stack<int> st;
        int r = n - 1;
        while (r > indices[i])
        {
            if (arr[r] > curr)
            {
                st.push(arr[r]);
            }
            r--;
        }
        ans[i] = st.size();
    }
    return ans;
}