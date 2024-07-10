// Input 1:
//     A = [4, 5, 2, 10, 8]
// Output 1:
//     G = [-1, 4, -1, 2, 2]

vector<int> Solution::prevSmaller(vector<int> &A)
{
    vector<int> sol(A.size(), -1);
    stack<int> st;

    for (int i = 0; i < A.size(); i++)
    {
        while (!st.empty() && st.top() >= A[i])
        {
            st.pop();
        }
        sol[i] = st.empty() ? -1 : st.top();
        st.push(A[i]);
    }

    return sol;
}
