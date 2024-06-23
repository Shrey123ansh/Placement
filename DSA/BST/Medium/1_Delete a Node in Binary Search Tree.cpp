TreeNode *helper(TreeNode *root)
{
    if (root->left == NULL && root->right == NULL)
        return NULL;
    else if (root->left == NULL)
        return root->right;
    else if (root->right == NULL)
        return root->left;
    else
    {
        TreeNode *leftRightNode = root->left;
        while (leftRightNode->right != NULL)
        {
            leftRightNode = leftRightNode->right;
        }

        leftRightNode->right = root->right;
        return root->left;
    }
}

TreeNode *deleteNode(TreeNode *root, int key)
{
    if (root == NULL)
        return NULL;

    if (root->val == key)
    {
        return helper(root);
    }

    TreeNode *dummy = root;

    while (root != NULL)
    {
        if (root->val > key)
        {
            if (root->left && root->left->val == key)
            {
                root->left = helper(root->left);
                break;
            }
            else
            {
                root = root->left;
            }
        }
        else
        {
            if (root->right && root->right->val == key)
            {
                root->right = helper(root->right);
                break;
            }
            else
            {
                root = root->right;
            }
        }
    }

    return dummy;
}