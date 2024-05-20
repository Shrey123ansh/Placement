ListNode *reverseList(ListNode *head)
{
    ListNode *prev = NULL;
    ListNode *curr = head;

    while (curr != NULL)
    {
        ListNode *nest = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nest;
    }
    return prev;
}

