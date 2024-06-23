long long int fun(string s, int k)
{
    long long int a[26] = {0};
    long long int n = s.size();
    long long int l = 0, r = 0;
    long long int count = 0;
    long long int flag = 1;
    long long int cnt = 0;
    while (r < n)
    {

        if (flag)
        {
            a[s[r] - 'a']++;

            if (a[s[r] - 'a'] == 1)
                cnt++;
        }

        if (cnt < k)
        {
            r++;
            flag = 1;
        }
        else
        {
            count = count + n - r;
            if (a[s[l] - 'a'] == 1)
                cnt--;
            a[s[l] - 'a']--;
            l++;
            flag = 0;
        }
    }

    return count;
}
long long int substrCount(string s, int k)
{

    long long int ans = 0;
    ans = fun(s, k) - fun(s, k + 1);
    return ans;
}