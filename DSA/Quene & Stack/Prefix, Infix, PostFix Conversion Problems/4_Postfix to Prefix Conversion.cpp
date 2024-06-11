bool isOperand(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
        return 1;
    else
        return 0;
}

string postToPre(string post_exp)
{
    // Write your code here
    stack<string> st;
    for (int i = 0; i < post_exp.size(); i++)
    {
        if (isOperand(post_exp[i]))
        {
            // Create a new string with the character at index i
            st.push(string(1, post_exp[i]));
        }
        else
        {
            string A = st.top();
            st.pop();
            string B = st.top();
            st.pop();
            st.push(post_exp[i] + B + A);
        }
    }
    return st.top();
}