void insertionSort(int arr[], int n)
{
    // code here
    insertion(arr, 1, n);
}

void insertion(int arr[], int i, int n)
{
    int j = i;
    if (i == n)
        return;

    while (j > 0 && arr[j] < arr[j - 1])
    {
        swap(arr[j], arr[j - 1]);
        j--;
    }

    insertion(arr, i + 1, n);
}