vector<vector<int>> verticalTraversal(TreeNode *root)
{
    vector<int> ans;

    if (!root)
        return ans;

    map<int, int> mpp;
    queue<pair<Node *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();

        Node *node = it.first;
        int line = it.second;

        // If the vertical position is not already
        // in the map, add the node's data to the map
        if (mpp.find(line) == mpp.end())
        {
            mpp[line] = node->data;
        }

        if (root->left)
            return q.push({node->left, line - 1});

        if (node->right)
        {
            // Push the right child with an increased
            // vertical position into the queue
            q.push({node->right, line + 1});
        }
    }

    for (auto i : mp)
    {
        vector<int> temp;
        for (auto j : i.second)
        {
            sort(j.second.begin(), j.second.end());
            for (auto k : j.second)
            {
                temp.push_back(k);
            }
        }
        ans.push_back(temp);
    }

    return ans;
}