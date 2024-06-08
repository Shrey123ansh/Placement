string longestCommonPrefix(vector<string> &strs)
{
    string ans = "";
    int end = strs.size() - 1;
    sort(strs.begin(), strs.end());
    for (int i = 0; i < strs[0].length(); i++)
    {
        if (strs[0][i] == strs[end][i])
            ans.push_back(strs[0][i]);
        else
            return ans;
    }
    return ans;
}