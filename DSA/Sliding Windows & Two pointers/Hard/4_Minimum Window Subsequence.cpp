Input: 
str1: geeksforgeeks
str2: eksrg
Output: 
eksforg
Explanation: 
"eksforg" satisfies all required conditions. str2 is its subsequence and it is longest and leftmost among all possible valid substrings of str1.
Example 2:

Input: 
str1: abcdebdde 
str2: bde 
Output:  bcde 
Explanation:  "bcde" is the answer and "deb" is not a smaller window because the elements in the window must occur in order.

string minWindow(string str1, string str2)
{
    // Write your Code here
    int s2 = str2.length();
    int s1 = str1.length();
    int win2 = 0;
    int len = INT_MAX, last = -1;
    string ans = "";
    for (int i = 0; i < s1; i++)
    {
        win2 = 0;
        int j = last + 1;
        while (j < s1 && win2 < s2)
        {
            if (win2 < s2 && str1[j] == str2[win2])
            {
                if (win2 == 0)
                    last = j;
                win2++;
            }
            if (win2 == (s2) && len > (j - last + 1))
            {
                len = min(len, j - last + 1);
                ans = str1.substr(last, j - last + 1);
            }
            j++;
        }
    }

    return ans;
}