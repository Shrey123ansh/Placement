
int largest(vector<int> &arr, int n)
{
    int temp = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= temp)
        {
            temp = arr[i];
        }
    }
    return temp;
}

int largest(vector<int> &arr, int n)
{
    sort(arr.begin(), arr.end());
    return arr[arr.size() - 1];
}
