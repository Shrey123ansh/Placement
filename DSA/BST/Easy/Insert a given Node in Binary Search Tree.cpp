TreeNode *insertIntoBST(TreeNode *root, int val)
{
    if (!root)
    {
        TreeNode *root = new TreeNode(val);
        return root;
    }
    if (val < root->val)
    {
        root->left = insertIntoBST(root->left, val);
    }
    else
    {
        root->right = insertIntoBST(root->right, val);
    }
    return root;
}