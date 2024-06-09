int extractMax()
{

    int res = H[0];

    H[0] = H[s];
    s--;

    int i = 0;

    while (i <= s)
    {
        int lid = 2 * i + 1;
        int rid = 2 * i + 2;

        if (H[lid] >= H[rid])
        {
            if (H[lid] > H[i])
            {
                swap(H[lid], H[i]);
                i = lid;
            }
            else
            {
                break;
            }
        }
        else
        {
            if (H[rid] > H[i])
            {
                swap(H[rid], H[i]);
                i = rid;
            }
            else
            {
                break;
            }
        }
    }
    return res;
}