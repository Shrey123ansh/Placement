int countNodes(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }

    // Initialize count variable to
    // store the number of nodes
    int count = 0;

    // Call the inorder traversal
    // function to count nodes
    inorder(root, count);

    // Return the final count of
    // nodes in the binary tree
    return count;
}

void inorder(TreeNode *root, int &count)
{
    // Base case: If the current
    // node is NULL, return
    if (root == NULL)
    {
        return;
    }

    // Increment count
    // for the current node
    count++;

    // Recursively call inorder
    // on the left subtree
    inorder(root->left, count);

    // Recursively call inorder
    // on the right subtree
    inorder(root->right, count);
}

/////////////////////////////////OR///////////////////////////////

int countNodes(TreeNode *root)
{
    // Base case: If the root
    // is NULL, there are no nodes
    if (root == NULL)
    {
        return 0;
    }

    // Find the left height and
    // right height of the tree
    int lh = findHeightLeft(root);
    int rh = findHeightRight(root);

    // Check if the last level
    // is completely filled
    if (lh == rh)
    {
        // If so, use the formula for
        // total nodes in a perfect
        // binary tree ie. 2^h - 1
        return (1 << lh) - 1;
    }

    // If the last level is not completely
    // filled, recursively count nodes in
    // left and right subtrees
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Function to find the left height of a tree
int findHeightLeft(TreeNode *node)
{
    int height = 0;
    // Traverse left child until
    // reaching the leftmost leaf
    while (node)
    {
        height++;
        node = node->left;
    }
    return height;
}

// Function to find the right height of a tree
int findHeightRight(TreeNode *node)
{
    int height = 0;
    // Traverse right child until
    // reaching the rightmost leaf
    while (node)
    {
        height++;
        node = node->right;
    }
    return height;
}