void MyStack ::push(int x) 
{
    // Your Code
    StackNode *newnode = new StackNode(x);
    if(top==nullptr) {
        top=newnode;
    }
    else{
        newnode->next=top;
        top=newnode;
    }
}

//Function to remove an item from top of the stack.
int MyStack ::pop() 
{
    // Your Code
    if(top==nullptr) return -1;
    
    StackNode *temp = top->next;
    int a = top->data;
    top->next=nullptr;
    top=temp;
    return a;
}