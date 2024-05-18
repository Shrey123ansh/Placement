int getCount(struct Node *head)
{

    // Code here
    Node *temp = head;

    if (head == NULL)
    {
        return 0;
    }
    if (head->next == NULL)
        return 1;

    int count = 1;

    while (temp->next != NULL)
    {
        temp = temp->next;
        count++;
    }

    return count;
}