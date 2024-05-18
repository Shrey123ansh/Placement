void getans(Node *root, int input, int &ans)
{
    if (root == nullptr)
        return;
    if (root->data >= input)
    {
        ans = root->data;
        getans(root->left, input, ans);
    }
    else
    {
        getans(root->right, input, ans);
    }
}

int findCeil(Node *root, int input)
{
    if (root == NULL)
        return -1;
    int ans = -1;
    getans(root, input, ans);
    return ans;
}