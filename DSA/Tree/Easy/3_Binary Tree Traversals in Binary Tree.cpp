void inor(TreeNode *root, vector<int> &v)
{
    if (root == NULL)
        return;
    inor(root->left, v);
    v.push_back(root->data);
    inor(root->right, v);
}
void preo(TreeNode *root, vector<int> &v)
{
    if (root == NULL)
        return;
    v.push_back(root->data);
    preo(root->left, v);
    preo(root->right, v);
}
void posto(TreeNode *root, vector<int> &v)
{
    if (root == NULL)
        return;
    posto(root->left, v);
    posto(root->right, v);
    v.push_back(root->data);
}

vector<vector<int>> getTreeTraversal(TreeNode *root)
{
    // Write your code here.
    vector<vector<int>> v(3);
    if (!root)
        return v;
    inor(root, v[0]);
    preo(root, v[1]);
    posto(root, v[2]);
    return v;
}