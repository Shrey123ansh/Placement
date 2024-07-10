// Input: s = "the sky is blue"
// Output: "blue is sky the"
string reverseWords(string s)
{
    int start = 0, end = s.length() - 1;
    string temp = "";
    string ans = "";

    while (start <= end)
    {
        char ch = s[start];
        if (ch != ' ')
        {
            temp += ch;
        }
        else if (ch == ' ')
        {
            if (ans != "")
            {
                ans = temp + " " + ans;
            }
            else
            {
                ans = temp;
                temp = "";
            }
            start++;
        }

        if (ans != "")
            ans = temp + " " + ans;
        else
            ans = temp;
    }
    return ans;
}

string reverseWords(string s)
{
    s += " ";
    stack<string> st;
    int i;
    string str = "";
    for (i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            st.push(str);
            str = "";
        }
        else
            str += s[i];
    }
    string ans = "";
    while (st.size() != 1)
    {
        ans += st.top() + " ";
        st.pop();
    }
    ans += st.top(); // The last word should'nt have a space after it
    return ans;
}
