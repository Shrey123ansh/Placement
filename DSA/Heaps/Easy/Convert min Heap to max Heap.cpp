bool isMaxHeap(int arr[], int n)
{
    // Your code goes here
    for (int i = (n / 2)-1; i >= 0; i--)
    {
        int rc = 2 * i + 2, lc = 2 * i + 1;

        if ((rc < n && arr[i] < arr[rc]) || (lc < n && arr[i] < arr[lc]))
            return false;
    }

    return true;
}