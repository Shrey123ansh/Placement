void bubbleSort(int arr[], int n)
{
    // Your code here
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}