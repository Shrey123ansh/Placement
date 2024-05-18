bool searchKey(int n, struct Node *head, int key)
{
    // Code here
    Node *temp = head;

    if (head == NULL)
    {
        return false;
    }

    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    }

    return false;
}