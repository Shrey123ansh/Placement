Example 1:

Input: cardPoints = [1,2,3,4,5,6,1], k = 3
Output: 12
Explanation: After the first step, your score will always be 1. However, choosing the rightmost card first will maximize your total score. The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.
Example 2:

Input: cardPoints = [2,2,2], k = 2
Output: 4
Explanation: Regardless of which two cards you take, your score will always be 4.
Example 3:

Input: cardPoints = [9,7,7,9,7,7,9], k = 7
Output: 55
Explanation: You have to take all the cards. Your score is the sum of points of all cards.

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
