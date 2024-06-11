int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string infixToPostfix(string s)
{
    // Your code here
    stack<int> st;
    string result;

    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];

        if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            result += c;
        }

        else if (c == '(')
            st.push('(');

        else if (c == ')')
        {
            while (st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && prec(c) <= prec(st.top()))
            {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }

    return result;
}

/////////////////////////////OR//////////////////////

bool isOperator(char c)
{
    return (!isalpha(c) && !isdigit(c));
}

int getPriority(char C)
{
    if (C == '-' || C == '+')
        return 1;
    else if (C == '*' || C == '/')
        return 2;
    else if (C == '^')
        return 3;
    return 0;
}

string infixToPostfix(string infix)
{
    infix = '(' + infix + ')';
    int l = infix.size();
    stack<char> char_stack;
    string output;

    for (int i = 0; i < l; i++)
    {

        // If the scanned character is an
        // operand, add it to output.
        if (isalpha(infix[i]) || isdigit(infix[i]))
            output += infix[i];

        // If the scanned character is an
        // ‘(‘, push it to the stack.
        else if (infix[i] == '(')
            char_stack.push('(');

        // If the scanned character is an
        // ‘)’, pop and output from the stack
        // until an ‘(‘ is encountered.
        else if (infix[i] == ')')
        {
            while (char_stack.top() != '(')
            {
                output += char_stack.top();
                char_stack.pop();
            }

            // Remove '(' from the stack
            char_stack.pop();
        }

        // Operator found
        else
        {
            if (isOperator(char_stack.top()))
            {
                if (infix[i] == '^')
                {
                    while (getPriority(infix[i]) <= getPriority(char_stack.top()))
                    {
                        output += char_stack.top();
                        char_stack.pop();
                    }
                }
                else
                {
                    while (getPriority(infix[i]) < getPriority(char_stack.top()))
                    {
                        output += char_stack.top();
                        char_stack.pop();
                    }
                }

                // Push current Operator on stack
                char_stack.push(infix[i]);
            }
        }
    }
    while (!char_stack.empty())
    {
        output += char_stack.top();
        char_stack.pop();
    }
    return output;
}