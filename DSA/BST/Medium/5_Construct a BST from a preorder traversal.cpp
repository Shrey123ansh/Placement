void insertnode(TreeNode *root, int value)
{
    if (value < root->val)
    {
        if (root->left == NULL)
            root->left = new TreeNode(value);
        else
            insertnode(root->left, value);
    }
    else
    {
        if (root->right == NULL)
            root->right = new TreeNode(value);
        else
            insertnode(root->right, value);
    }
}

TreeNode *bstFromPreorder(vector<int> &preorder)
{
    TreeNode *root = new TreeNode;
    root->val = preorder[0];

    for (int i = 1; i < preorder.size(); i++)
    {
        insertnode(root, preorder[i]);
    }
    return root;
}