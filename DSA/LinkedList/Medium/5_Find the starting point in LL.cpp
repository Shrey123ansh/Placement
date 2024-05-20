Node *detectLoop(Node *head)
{

    // Use temp to traverse the linked list
    Node *temp = head;

    // hashmap to store all visited nodes
    unordered_map<Node *, int> mp;

    // Traverse the list using temp
    while (temp != NULL)
    {
        // check if temp has been encountered again
        if (mp.count(temp) != 0)
        {
            // A loop is detected hence return temp
            return temp;
        }
        // store temp as visited
        mp[temp] = 1;
        // iterate through the list
        temp = temp->next;
    }

    // If no loop is detected, return nullptr
    return nullptr;
}

ListNode *detectCycle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;
}