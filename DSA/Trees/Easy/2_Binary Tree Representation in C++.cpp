void create_tree(node *root0, vector<int> &vec)
{
    // Your code goes here
    int n = vec.size();
    queue<struct node *> q;
    q.push(root0);

    for (int i = 0; i < n / 2; i++)
    {
        struct node *temp = q.front();
        q.pop();

        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n)
            temp->left = newNode(vec[left]);
        if (right < n)
            temp->right = newNode(vec[right]);
        q.push(temp->left);
        q.push(temp->right);
    }
}