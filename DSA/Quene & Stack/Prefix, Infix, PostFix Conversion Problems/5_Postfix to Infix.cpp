string postToInfix(string exp)
{
    stack<string> st;
    for (int i = 0; i < exp.size(); i++)
    {
        if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')
        {
            string s2 = st.top();
            st.pop();
            string s1 = st.top();
            st.pop();
            st.push('(' + s1 + exp[i] + s2 + ')');
        }
        else
        {
            string temp = "";
            temp += exp[i];
            st.push(temp);
        }
    }
    return st.top();
}