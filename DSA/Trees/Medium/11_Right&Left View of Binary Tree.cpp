vector<int> rightSideView(TreeNode *root)
{
    vector<int> res;

    vector<vector<int>> levelvector = levelOrder(root);

    for (auto level : levelvector)
    {
        res.push_back(level.back());
    }

    return res;
}

vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> ans;

    // Return an empty vector
    // if the tree is empty
    if (!root)
    {
        return ans;
    }

    // Use a queue to perform
    // level order traversal
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        vector<int> level;

        // Process each node
        // in the current level
        for (int i = 0; i < size; i++)
        {
            TreeNode *top = q.front();
            level.push_back(top->val);
            q.pop();

            // Enqueue the left
            // child if it exists
            if (top->left != NULL)
            {
                q.push(top->left);
            }

            // Enqueue the right
            // child if it exists
            if (top->right != NULL)
            {
                q.push(top->right);
            }
        }

        // Add the current
        // level to the result
        ans.push_back(level);
    }

    return ans;
}

////////////////////////OR/////////////////////////////

vector<int> rightsideView(TreeNode *root)
{
    // Vector to store the result
    vector<int> res;

    // Call the recursive function
    // to populate the right-side view
    recursionRight(root, 0, res);

    return res;
}

void recursionRight(TreeNode *root, int level, vector<int> &res)
{
    // Check if the current node is NULL
    if (root == NULL)
    {
        return;
    }

    // Check if the size of the result vector
    // is equal to the current level
    if (res.size() == level)
    {
        // If equal, add the value of the
        // current node to the result vector
        res.push_back(root->val);

        // Recursively call the function for the
        // right child with an increased level
        recursionRight(root->right, level + 1, res);

        // Recursively call the function for the
        // left child with an increased level
        recursionRight(root->left, level + 1, res);
    }
}