
vector<int> leaders(int a[], int n)
{
    // Code here
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        bool leader = true;

        for (int j = i + 1; j < n; j++)
            if (a[j] > a[i])
            {

                leader = false;
                break;
            }

        if (leader)
            ans.push_back(a[i]);
    }

    return ans;
}

vector<int> leaders(int a[], int n)
{
    // Code here
    vector<int> ans;

    // Last element of an array is always a leader,
    // push into ans array.
    int maxi = a[n - 1];
    ans.push_back(a[n - 1]);

    // Start checking from the end whether a number is greater
    // than max no. from right, hence leader.
    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] > maxi)
        {
            ans.push_back(a[i]);
            maxi = a[i];
        }
    }

    return ans;
}