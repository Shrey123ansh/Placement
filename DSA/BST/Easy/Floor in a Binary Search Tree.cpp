void getans(Node *root, int input, int &ans)
{
    if (root == nullptr)
        return;
    if (root->data <= input)
    {
        ans = root->data;
        getans(root->right, input, ans);
    }
    else
    {
        getans(root->left, input, ans);
    }
}

int findFloor(Node *root, int input)
{
    if (root == NULL)
        return -1;
    int ans = -1;
    getans(root, input, ans);
    return ans;
}