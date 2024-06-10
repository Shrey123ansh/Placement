int median(vector<vector<int>> &matrix, int m, int n)
{
    vector<int> lst;

    // traverse the matrix and
    // copy the elements to list:
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            lst.push_back(matrix[i][j]);
        }
    }

    // sort the list:
    sort(lst.begin(), lst.end());
    return lst[(m * n) / 2];
}
