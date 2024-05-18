Node *constructLL(vector<int> &arr)
{
    // code here
    Node *newHead = new Node(arr[0]);
    Node *temp = newHead;

    for (int i = 1; i < arr.size(); i++)
    {
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }
    return newHead;
}