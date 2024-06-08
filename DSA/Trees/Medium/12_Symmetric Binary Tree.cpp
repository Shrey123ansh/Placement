bool isSymmetric(TreeNode *root)
{
    if (!root)
    {
        // An empty tree is
        // considered symmetric
        return true;
    }
    // Call the utility function
    // to check symmetry of subtrees
    return isSymmetricUtil(root->left, root->right);
}

bool isSymmetricUtil(TreeNode *root1, TreeNode *root2)
{
    if (root1 == NULL || root2 == NULL)
    {
        // If one subtree is NULL, the other
        // must also be NULL for symmetry
        return root1 == root2;
    }

    return (root1->val == root2->val) && isSymmetricUtil(root1->left, root2->right) && isSymmetricUtil(root1->right, root2->left);
}