// Example 1:
// Input: strs = ["flower","flow","flight"]
// Output: "fl"
    
// Example 2:
// Input: strs = ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.
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
