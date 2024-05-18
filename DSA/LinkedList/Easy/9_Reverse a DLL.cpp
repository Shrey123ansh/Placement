Node *reverseDLL(Node *head)
{
    // Your code here
    Node *currptr = head;
    Node *prevptr = NULL;
    Node *nextptr;

    while (currptr != NULL)
    {
        nextptr = currptr->next;
        currptr->prev = nextptr;
        currptr->next = prevptr;

        prevptr = currptr;
        currptr = nextptr;
    }
    return prevptr;
}