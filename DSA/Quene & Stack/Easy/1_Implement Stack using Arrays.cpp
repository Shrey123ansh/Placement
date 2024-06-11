void MyStack ::push(int x)
{
    // Your Code
    arr[++top] = x;
}

// Function to remove an item from top of the stack.
int MyStack ::pop()
{
    // Your Code
    return (top == -1) ? -1 : arr[top--];
}