ListNode *middleNode(ListNode *head)
{
    ListNode *temp = head;
    int count = 0;

    if (head->next == NULL)
        return head;

    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    int n = (count) / 2;
    temp = head;

    while (temp != NULL)
    {
        temp = temp->next;
        n--;

        if (n == 0)
            break;
    }

    return temp;
}

ListNode *middleNode(ListNode *head)
{
    ListNode *temp = head;
    ListNode *temp2 = head;

    if (head->next == NULL)
        return head;

    while (temp2 != NULL && temp2->next != NULL)
    {
        temp = temp->next;
        temp2 = temp2->next->next;
    }

    return temp;
}