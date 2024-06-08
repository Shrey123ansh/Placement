void path(Node *root, vector<vector<int>> &res, vector<int> &temp)
{
    if (!root)
        return;
    if (!root->left && !root->right)
    {
        temp.push_back(root->data);
        res.push_back(temp);
        temp.pop_back();
        return;
    }
    temp.push_back(root->data);
    path(root->left, res, temp);
    path(root->right, res, temp);
    temp.pop_back();
}

vector<vector<int>> Paths(Node *root)
{
    // code here
    vector<int> temp;
    vector<vector<int>> res;
    path(root, res, temp);
    return res;
}
