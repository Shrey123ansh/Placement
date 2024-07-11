Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
Example 2:
Input: head = [0,1,2], k = 4
Output: [2,0,1]
 
 
 node *rotateRight(node *head, int k)
{
    if (head == NULL || head->next == NULL)
        return head;
    for (int i = 0; i < k; i++)
    {
        node *temp = head;
        while (temp->next->next != NULL)
            temp = temp->next;
        node *end = temp->next;
        temp->next = NULL;
        end->next = head;
        head = end;
    }
    return head;
}