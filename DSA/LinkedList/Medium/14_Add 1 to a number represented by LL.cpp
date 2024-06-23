int val(Node *head)
{
    if (!head)
        return 1;
    int fl = val(head->next);
    if (fl == 1)
    {
        int x = head->data;
        if (x + 1 < 10)
        {
            head->data = x + 1;
            return 0;
        }
        else
        {
            head->data = 0;
            return 1;
        }
    }
    else
        return 0;
}

Node *addOne(Node *head)
{
    if (!head)
        return NULL;

    Node *temp = head;
    int x = val(temp);
    if (x == 1)
    {
        Node *ans = new Node(1);
        ans->next = head;
        return ans;
    }
    return head;
}