vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> ans;

    if (root == NULL)
        return ans;

    queue<TreeNode *> q;
    q.push(root);
    bool lefttoright = true;

    while (!q.empty())
    {
        int size = q.size() - 1;
        vector<int> level(size);
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front();
            q.pop();

            int index = lefttoright ? i : (size - 1 - i);

            level[index] = node->val;

            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
        }
        lefttoright = !lefttoright;
        ans.push_back(level);
    }

    return ans;
}