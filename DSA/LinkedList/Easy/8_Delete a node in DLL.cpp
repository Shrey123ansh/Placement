Node *deleteNode(Node *head, int x)
{
    // Your code here
    int c = 1;
    Node *curr = head;
    while (c != x)
    {
        curr = curr->next;
        c++;
    }
    if (curr->prev == NULL)
    {
        curr = curr->next;
        curr->prev = NULL;
        head->next = NULL;
        return curr;
    }
    else if (curr->next == NULL)
    {
        curr->prev->next = NULL;
        curr->prev = NULL;
        return head;
    }
    else
    {
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        curr->prev = NULL;
        curr->next = NULL;
        return head;
    }
}