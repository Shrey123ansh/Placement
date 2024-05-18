void deleteNode(ListNode *node)
{
    ListNode *prev; // save refernece to previous node
    while (node->next != NULL)
    {
        prev = node;
        node->val = node->next->val;
        node = node->next;
    }
    // when we have reached to last node then we have to remove it
    // this can be done by assigning null to previous->next
    prev->next = NULL;
}