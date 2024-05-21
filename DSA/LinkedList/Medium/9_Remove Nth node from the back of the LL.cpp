ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *slow = head;
    ListNode *fast = head;

    for (int i = 0; i < n; i++)
    {
        fast = fast->next;
    }

    while (fast != nullptr)
    {
        slow = slow->next;
        fast = fast->next;
    }

    ListNode *temp = slow->next;
    slow->next = slow->next->next;

    delete temp;
    return head;
}