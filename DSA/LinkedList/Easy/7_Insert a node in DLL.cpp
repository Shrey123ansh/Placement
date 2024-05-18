void addNode(Node *head, int pos, int data)
{
    // Your code here
    Node *temp = head;
    Node *newNode = new Node(data);

    for (int i = 0; i < pos; i++)
    {
        temp = temp->next;
    }

    Node *wait = temp->next;
    if (temp->next == NULL)
    {
        temp->next = newNode;
        newNode->prev = temp;
        return;
    }

    newNode->prev = temp;
    temp->next = newNode;
    newNode->next = wait;
    wait->prev = newNode;
}