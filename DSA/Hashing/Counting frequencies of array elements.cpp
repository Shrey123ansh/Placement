void frequencyCount(vector<int> &arr, int N, int P)
{
    // code here
    unordered_map<int, int> mp;
    for (int i = 0; i < arr.size(); i++)
    {
        mp[arr[i]]++;
    }

    for (int i = 0; i < N; i++)
    {
        arr[i] = mp[i + 1];
    }
}