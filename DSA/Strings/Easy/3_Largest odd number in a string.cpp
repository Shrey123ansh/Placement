string largestOddNumber(string num)
{
    int n = num.length();
    for (int s = n - 1; s >= 0; s--)
    {
        int val = num[s] - '0';
        if (val % 2 == 0)
            num.pop_back();
        else
            return num;
    }
    return "";
}