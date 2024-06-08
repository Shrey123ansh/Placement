bool isAnagram(string str1, string str2)
{
    if (str1.length() != str2.length())
        return false;

    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    // Case 2: check if every character of str1 and str2 matches with each other
    for (int i = 0; i < str1.length(); i++)
    {
        if (str1[i] != str2[i])
            return false;
    }
    return true;
}

bool isAnagram(string str1, string str2)
{
    if (str1.length() != str2.length())
        return false;

    int freq[26] = {0};
    for (int i = 0; i < str1.length(); i++)
    {
        freq[str1[i] - 'A']++;
    }
    for (int i = 0; i < str2.length(); i++)
    {
        freq[str2[i] - 'A']--;
    }
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] != 0)
            return false;
    }
    return true;
}