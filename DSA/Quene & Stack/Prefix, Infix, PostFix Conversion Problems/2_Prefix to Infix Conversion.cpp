tring preToInfix(string pre_exp)
{
    // Write your code here
    stack<string> st;
    for (int i = pre_exp.size() - 1; i >= 0; i--)
    {
        char ch = pre_exp[i];
        if (ch == '^' || ch == '/' || ch == '*' || ch == '+' || ch == '-')
        {
            string exp = "(" + st.top() + ch;
            st.pop();
            exp += st.top() + ")";
            st.pop();
            st.push(exp);
        }
        else
        {
            string temp = "";
            temp += ch;
            st.push(temp);
        }
    }
    return st.top();
}