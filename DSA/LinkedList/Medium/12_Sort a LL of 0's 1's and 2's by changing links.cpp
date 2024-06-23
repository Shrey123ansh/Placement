Node *segregate(Node *head)
{

    // Add code here
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == 0)
            count0++;
        if (temp->data == 1)
            count1++;
        if (temp->data == 2)
            count2++;
        temp = temp->next;
    }
    temp = head;
    for (int i = 0; i < count0; i++)
    {
        temp->data = 0;
        temp = temp->next;
    }
    for (int i = count0; i < count0 + count1; i++)
    {
        temp->data = 1;
        temp = temp->next;
    }
    while (temp != NULL)
    {
        temp->data = 2;
        temp = temp->next;
    }
    return head;
}

///////////////////////OR////////////////////////

ListNode *segregate(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    ListNode *temp = NULL;
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        temp = slow;
        slow = slow->next;
        fast = fast->next;
    }
    temp->next = NULL;

    ListNode *l1 = segregate(head);
    ListNode *l2 = segregate(slow);
    return mergeList(l1, l2);
}

ListNode *mergeList(ListNode *l1, ListNode *l2)
{
    ListNode *ptr = new ListNode(0);
    ListNode *curr = ptr;

    while (l1 != NULL && l2 != NULL)
    {
        if (l1->val <= l2->val)
        {
            curr->next = l1;
            l1 = l1->next;
        }
        else
        {
            curr->next = l2;
            l2 = l2->next;
        }

        curr = curr->next;
    }

    if (l1 != NULL)
    {
        curr->next = l1;
        l1 = l1->next;
    }

    if (l2 != NULL)
    {
        curr->next = l2;
        l2 = l2->next;
    }

    return ptr->next;
}