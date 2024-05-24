vector<int> res;
void inorder(TreeNode *p)
{
    if (!p)
        return;
    inorder(p->left);
    res.push_back(p->val);
    inorder(p->right);
}
int kthSmallest(TreeNode *root, int k)
{
    inorder(root);
    return res[k - 1];
}