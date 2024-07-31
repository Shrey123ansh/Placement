Example 1:

Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 
Example 2:

Input: s = "aaacb"
Output: 3
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 
Example 3:

Input: s = "abc"
Output: 1

int maxScore(vector<int> &cardPoints, int k)
{
    int leftsum = 0, rightsum = 0;

    for (int i = 0; i < k; i++)
    {
        leftsum += cardPoints[i];
    }

    int maxsum = leftsum;

    int left = k - 1, right = cardPoints.size() - 1;

    while (left >= 0)
    {
        leftsum -= cardPoints[left];  // Remove card from the left end of the initial k cards
        leftsum += cardPoints[right]; // Add card from the right end of the array

        maxsum = max(maxsum, leftsum);

        left--;
        right--;
    }

    return maxsum;
}
