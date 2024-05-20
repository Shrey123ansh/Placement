vector<int> rearrangeArray(vector<int> &nums)
{
    vector<int> pos;
    vector<int> neg;

    // Segregate the array into positives and negatives.
    for (int i = 0; i < nums.size(); i++)
    {

        if (nums[i] > 0)
            pos.push_back(nums[i]);
        else
            neg.push_back(nums[i]);
    }

    // Positives on even indices, negatives on odd.
    for (int i = 0; i < (nums.size() / 2); i++)
    {

        nums[2 * i] = pos[i];
        nums[2 * i + 1] = neg[i];
    }

    return nums;
}

vector<int> rearrangeArray(vector<int> &nums)
{
    vector<int> ans(nums.size(), 0);
    int posint = 0;
    int negint = 1;

    // Segregate the array into positives and negatives.
    for (int i = 0; i < nums.size(); i++)
    {

        if (nums[i] > 0)
        {
            ans[posint] = nums[i];
            posint += 2;
        }
        else
        {
            ans[negint] = nums[i];
            negint += 2;
        }
    }

    return ans;
}