void bubbleSort(int arr[], int n)
{
    // Your code here
    if (n == 1)
        return;

    for (int j = 0; j < n - 1; j++)
    {
        if (arr[j] > arr[j + 1])
        {
            int temp = arr[j + 1];
            arr[j + 1] = arr[j];
            arr[j] = temp;
        }
    }

    bubbleSort(arr, n - 1);
}