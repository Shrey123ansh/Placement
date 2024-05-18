int lenOfLongSubarr(int A[], int N, int K)
{
    // Complete the function
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum = sum + A[i];
        if (sum > K)
        {
            sum = 0;
        }
        else if (sum > K)
    }
}