int isSumProperty(Node *root)
{
    // Add your code here
    if (root == NULL)
    {
        return 1;
    }

    // Calculate the sum of the values of
    // the left and right children, if they exist.
    int child = 0;
    if (root->left)
    {
        child += root->left->data;
    }
    if (root->right)
    {
        child += root->right->data;
    }

    // Compare the sum of children with
    // the current node's value and update
    if (child >= root->data)
    {
        root->data = child;
    }
    else
    {
        // If the sum is smaller, update the
        // child with the current node's value.
        if (root->left)
        {
            root->left->data = root->data;
        }
        else if (root->right)
        {
            root->right->data = root->data;
        }
    }

    // Recursively call the function
    // on the left and right children.
    isSumProperty(root->left);
    isSumProperty(root->right);

    // Calculate the total sum of the
    // values of the left and right
    // children, if they exist.
    int tot = 0;
    if (root->left)
    {
        tot += root->left->data;
    }
    if (root->right)
    {
        tot += root->right->data;
    }

    // If either left or right child
    // exists, update the current node's
    // value with the total sum.
    if (root->left or root->right)
    {
        root->data = tot;
    }
}