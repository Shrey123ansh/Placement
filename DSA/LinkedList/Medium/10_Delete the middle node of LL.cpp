ListNode *deleteMiddle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *prev;

    if (head->next == NULL)
        return NULL;

    while (fast != NULL && fast->next != NULL)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode *temp = prev->next;
    prev->next = slow->next;

    delete temp;
    return head;
}