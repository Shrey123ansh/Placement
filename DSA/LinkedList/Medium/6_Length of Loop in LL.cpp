int countNodesinLoop(struct Node *head)
{
    // edge case
    if (head == NULL || head->next == NULL)
    {
        return 0;
    }
    Node *fast = head->next->next;
    Node *slow = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        if (slow == fast)
        {

            // loop is present
            int cnt = 1;
            slow = slow->next;
            while (slow != fast)
            {
                cnt = cnt + 1;
                slow = slow->next;
            }
            return cnt;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return 0;
}
