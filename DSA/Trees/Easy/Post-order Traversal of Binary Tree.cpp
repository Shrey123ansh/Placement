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
    preorder(root->right, arr);
    arr.push_back(root->val);
}

/////////////////OR////////////////////////

vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> nodes;
    stack<TreeNode *> todo;
    TreeNode *last = NULL;
    while (root || !todo.empty())
    {
        if (root)
        {
            todo.push(root);
            root = root->left;
        }
        else
        {
            TreeNode *node = todo.top();
            if (node->right && last != node->right)
            {
                root = node->right;
            }
            else
            {
                nodes.push_back(node->val);
                last = node;
                todo.pop();
            }
        }
    }
    return nodes;
}

/////////////////OR////////////////////////

vector<int> postOrder(Node *root)
{
    // Vector to store
    // postorder traversal
    vector<int> postorder;

    // If the tree is empty,
    // return an empty traversal
    if (root == NULL)
    {
        return postorder;
    }

    // Two stacks for
    // iterative traversal
    stack<Node *> st1, st2;

    // Push the root node
    // onto the first stack
    st1.push(root);

    // Iterative traversal to populate
    // st2 with nodes in postorder
    while (!st1.empty())
    {
        // Get the top node from st1
        root = st1.top();
        st1.pop();

        // Push the node onto st2
        st2.push(root);

        // Push left child onto st1 if exists
        if (root->left != NULL)
        {
            st1.push(root->left);
        }

        // Push right child onto st1 if exists
        if (root->right != NULL)
        {
            st1.push(root->right);
        }
    }

    // Populate the postorder traversal
    // vector by popping st2
    while (!st2.empty())
    {
        postorder.push_back(st2.top()->data);
        st2.pop();
    }

    // Return the
    // postorder traversal
    return postorder;
}
