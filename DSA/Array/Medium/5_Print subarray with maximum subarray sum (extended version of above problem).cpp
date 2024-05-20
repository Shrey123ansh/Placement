int majorityElement(vector<int> v)
{

    // size of the given array:
    int n = v.size();

    for (int i = 0; i < n; i++)
    {
        // selected element is v[i]
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            // counting the frequency of v[i]
            if (v[j] == v[i])
            {
                cnt++;
            }
        }

        // check if frquency is greater than n/2:
        if (cnt > (n / 2))
            return v[i];
    }

    return -1;
}

int majorityElement(vector<int> v)
{

    // size of the given array:
    int n = v.size();

    // declaring a map:
    map<int, int> mpp;

    // storing the elements with its occurnce:
    for (int i = 0; i < n; i++)
    {
        mpp[v[i]]++;
    }

    // searching for the majority element:
    for (auto it : mpp)
    {
        if (it.second > (n / 2))
        {
            return it.first;
        }
    }

    return -1;
};

int majorityElement(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
        return -1;

    int el, el1;
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        if (cnt == 0)
        {
            el = nums[i];
            cnt = 1;
        }
        else if (nums[i] == el)
        {
            cnt++;
        }
        else
        {
            el1 = nums[i];
            cnt--;
        }
    }

    if (cnt >= 0)
        return el;
    else
        return el1;
}