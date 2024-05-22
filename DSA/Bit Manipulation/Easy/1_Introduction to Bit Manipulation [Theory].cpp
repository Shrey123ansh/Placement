void bitManipulation(int num, int i)
{
    // your code here
    int onmask = (1 << (i - 1));
    int offmask = ~(1 << (i - 1));

    // For get ith
    int a = num & onmask;

    if (a == 0)
        cout << 0 << " ";
    else if (a != 0)
        cout << 1 << " ";
    // For set ith
    cout << (num | onmask) << " ";
    // For clear ith
    cout << (num & offmask) << " ";
}