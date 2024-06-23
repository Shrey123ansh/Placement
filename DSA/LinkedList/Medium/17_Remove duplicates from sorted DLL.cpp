Node *removeDuplicates(struct Node *head)
{
    Node *p = head;
    Node *t = head->next;

    while (t != NULL)
    {
        if (p->data == t->data)
        {
            t = t->next;
            p->next = t;
            if (t != NULL)
                t->prev = p;
        }
        else
        {
            t = t->next;
            p = p->next;
        }
    }
    return (head);
}