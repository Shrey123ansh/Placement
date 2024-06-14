int totalFruits(int N, vector<int> &fruits)
{
    int maxlen = 0;
    int l = 0, r = 0;
    unordered_map<int, int> m;

    while (r < N)
    {
        m[fruits[r]]++;
        if (m.size() <= 2)
        {
            maxlen = max(maxlen, r - l + 1);
        }
        while (m.size() > 2)
        {
            m[fruits[l]]--;
            if (m[fruits[l]] == 0)
            {
                m.erase(fruits[l]);
            }
            l++;
        }
        r++;
    }
    return maxlen;
}

// TC: O(N) + O(N) = O(2N)
// SC: O(3)

int totalFruits(int N, vector<int> &fruits)
{
    int maxlen = 0;
    int l = 0, r = 0;
    unordered_map<int, int> m;

    while (r < N)
    {
        m[fruits[r]]++;
        if (m.size() <= 2)
        {
            maxlen = max(maxlen, r - l + 1);
        }
        else if (m.size() > 2)
        {
            m[fruits[l]]--;
            if (m[fruits[l]] == 0)
            {
                m.erase(fruits[l]);
            }
            l++;
        }
        r++;
    }
    return maxlen;
}

// TC: O(N)
// SC: O(3)