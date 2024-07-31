Input: arr[]= [2, 1, 2]
Output: 3
Explanation: We can pick one fruit from all three trees. Please note that the type of fruits is same in the 1st and 3rd baskets.
Input: arr[] = [3, 1, 2, 2, 2, 2]
Output: 5
Explanation: It's optimal to pick from the last 5 trees. Please note that we do not pick the first basket as we would have to stop at thrid tree which would result in only 2 fruits collected.
   
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
