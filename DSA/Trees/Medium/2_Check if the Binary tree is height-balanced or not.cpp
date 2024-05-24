int maxDepth(TreeNode *root)
{
    if (root == NULL)
        return 0;

    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

bool isBalanced(TreeNode *root)
{

    if (root == nullptr)
    {
        return true;
    }
    int lefttreeheight = maxDepth(root->left);
    int righttreeheight = maxDepth(root->right);

    if (abs(lefttreeheight - righttreeheight) <= 1 &&
        isBalanced(root->left) &&
        isBalanced(root->right))
    {
        return true;
    }
    return false;
}