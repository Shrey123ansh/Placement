ListNode *oddEvenList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    ListNode *odd = head;
    ListNode *even = head->next;
    ListNode *evenhead = even;
    while (even != NULL && even->next != NULL)
    {
        odd->next = even->next;
        odd = odd->next;

        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenhead;
    return head;
}

ListNode *oddEvenList(ListNode *head)
{
    ListNode *temp = head;
    ListNode *odd = new ListNode(-1);
    ListNode *even = new ListNode(-1);
    ListNode *todd = odd;
    ListNode *teven = even;
    int i = 1; // index
    while (temp != NULL)
    {
        if (i % 2 != 0)
        {
            todd->next = temp;
            todd = todd->next;
        }
        else
        {
            teven->next = temp;
            teven = teven->next;
        }
        i++;
        temp = temp->next;
    }
    teven->next = NULL;
    todd->next = even->next;
    return odd->next;
}