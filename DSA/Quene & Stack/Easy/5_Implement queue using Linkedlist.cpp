void MyQueue::push(int x)
{
    // Your Code
    QueueNode *temp = new QueueNode(x);
    if (front == NULL)
    {
        front = temp;
        rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}

// Function to pop front element from the queue.
int MyQueue ::pop()
{
    // Your Code
    if (front == NULL)
        return -1;
    QueueNode *temp = front;
    front = front->next;
    if (front == NULL)
        rear = NULL;
    int res = temp->data;
    delete (temp);
    return res;
}