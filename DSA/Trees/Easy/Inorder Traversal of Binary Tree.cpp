vector<int> preorderTraversal(TreeNode *root)
{

    vector<int> arr;
    preorder(root, arr);
    return arr;
}

void preorder(TreeNode *root, vector<int> &arr)
{

    if (root == NULL)
        return;

    preorder(root->left, arr);
    arr.push_back(root->val);
    preorder(root->right, arr);
}