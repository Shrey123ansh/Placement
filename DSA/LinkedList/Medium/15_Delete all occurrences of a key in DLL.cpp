void deleteAllOccurOfX(struct Node **head_ref, int x)
{
    // Write your code here

    struct Node *curr = *head_ref;

    while (curr)
    {
        if (curr->data == x)
        {
            if (curr->prev != NULL)
            {
                curr->prev->next = curr->next;
            }
            else
            {
                *head_ref = curr->next;
            }
            if (curr->next != NULL)
            {
                curr->next->prev = curr->prev;
            }
        }

        curr = curr->next;
    }
}