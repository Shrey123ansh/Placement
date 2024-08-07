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

vector<int> inorderTraversal(TreeNode *root)
{
    // Initialize a vector to store the result (in-order traversal)
    vector<int> res;

    // Initialize a stack for iterative traversal
    stack<TreeNode *> stack;

    // Loop until either the current node is not null or the stack is not empty
    while (root != nullptr || !stack.empty())
    {
        // Traverse to the leftmost node and push each encountered node onto the stack
        while (root != nullptr)
        {
            stack.push(root);
            root = root->left;
        }

        // Pop the last node from the stack (most recently left-visited node)
        root = stack.top();
        stack.pop();

        // Append the value of the popped node to the result vector
        res.push_back(root->val);

        // Move to the right subtree to continue the in-order traversal
        root = root->right;
    }

    // Return the final result vector
    return res;
}
}
;