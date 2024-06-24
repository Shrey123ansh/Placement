TreeNode *prev = NULL;
void flatten(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    // Recursive call to
    // flatten the right subtree
    flatten(root->right);

    // Recursive call to
    // flatten the left subtree
    flatten(root->left);

    // At this point, both left and right
    // subtrees are flattened, and 'prev'
    // is pointing to the rightmost node
    // in the flattened right subtree.

    // Set the right child of
    // the current node to 'prev'.
    root->right = prev;

    // Set the left child of the
    // current node to NULL.
    root->left = NULL;

    // Update 'prev' to the current
    // node for the next iteration.
    prev = root;
}

///////////////////OR////////////////////////////
TreeNode *prev = NULL;

// Function to flatten a binary tree
// to a right next Linked List structure
void flatten(TreeNode *root)
{
    // Base case: If the current
    // node is NULL, return.
    if (root == NULL)
    {
        return;
    }
    // Use a stack for
    // iterative traversal.
    stack<TreeNode *> st;
    // Push the root node
    // onto the stack.
    st.push(root);

    // Continue the loop until
    // the stack is empty.
    while (!st.empty())
    {
        // Get the top node from the stack.
        TreeNode *cur = st.top();
        // Pop the top node.
        st.pop();

        if (cur->right != NULL)
        {
            // Push the right child
            // onto the stack.
            st.push(cur->right);
        }

        if (cur->left != NULL)
        {
            // Push the left child
            // onto the stack.
            st.push(cur->left);
        }

        if (!st.empty())
        {
            // Connect the right child to
            // the next node in the stack.
            cur->right = st.top();
        }

        // Set the left child to NULL to
        // form a right-oriented linked list.
        cur->left = NULL;
    }
}

///////////////////OR////////////////////////////
void flatten(TreeNode *root)
{
    // Initialize a pointer
    // 'curr' to the root of the tree
    TreeNode *curr = root;

    // Iterate until 'curr'
    // becomes NULL
    while (curr)
    {
        // Check if the current
        // node has a left child
        if (curr->left)
        {
            // If yes, find the rightmost
            // node in the left subtree
            TreeNode *pre = curr->left;
            while (pre->right)
            {
                pre = pre->right;
            }

            // Connect the rightmost node in
            // the left subtree to the current
            //  node's right child
            pre->right = curr->right;

            // Move the entire left subtree to the
            // right child of the current node
            curr->right = curr->left;

            // Set the left child of
            // the current node to NULL
            curr->left = NULL;
        }

        // Move to the next node
        // on the right side
        curr = curr->right;
    }
}