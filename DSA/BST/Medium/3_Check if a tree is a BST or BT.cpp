bool isValidBST(TreeNode *root)
{
    long long int mini = -1000000000000, maxi = 1000000000000;

    return isBST(root, mini, maxi);
}
bool isBST(TreeNode *root, long long mini, long long maxi)
{
    if (root == NULL)
        return true;

    if (root->val > mini && root->val < maxi)
    {
        bool left = isBST(root->left, mini, root->val);
        bool right = isBST(root->right, root->val, maxi);

        return left && right;
    }
    else
    {
        return false;
    }
}