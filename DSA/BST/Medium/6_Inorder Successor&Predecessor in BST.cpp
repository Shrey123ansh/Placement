void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
{
    // Base case
    if (root == NULL)
        return;

    // If key is present at root
    if (root->key == key)
    {
        // the maximum value in left subtree is predecessor
        if (root->left != NULL)
        {
            Node *tmp = root->left;
            while (tmp->right)
                tmp = tmp->right;
            pre = tmp;
        }

        // the minimum value in right subtree is successor
        if (root->right != NULL)
        {
            Node *tmp = root->right;
            while (tmp->left)
                tmp = tmp->left;
            suc = tmp;
        }
        return;
    }

    // If key is smaller than root's key, go to left subtree
    if (root->key > key)
    {
        suc = root;
        findPreSuc(root->left, pre, suc, key);
    }
    else // go to right subtree
    {
        pre = root;
        findPreSuc(root->right, pre, suc, key);
    }
}

void find_p_s(Node *root, int a,
              Node **p, Node **q)
{
    // If root is null return
    if (!root)
        return;

    // traverse the left subtree
    find_p_s(root->left, a, p, q);

    // root data is greater than a
    if (root && root->data > a)
    {

        // q stores the node whose data is greater
        // than a and is smaller than the previously
        // stored data in *q which is successor
        if ((!*q) || (*q) && (*q)->data > root->data)
            *q = root;
    }

    // if the root data is smaller than
    // store it in p which is predecessor
    else if (root && root->data < a)
    {
        *p = root;
    }

    // traverse the right subtree
    find_p_s(root->right, a, p, q);
}

void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
{
    // set pre and suc as NULL initially
    pre = NULL;
    suc = NULL;

    // set temp node as root
    Node *temp1 = root;
    while (temp1)
    {
        // the maximum value in left subtree is successor
        if (temp1->key > key)
        {
            suc = temp1;
            temp1 = temp1->left;
        }
        else
            temp1 = temp1->right;
    }
    Node *temp2 = root;
    while (temp2)
    {
        // the minimum value in right subtree is predecessor
        if (temp2->key < key)
        {
            pre = temp2;
            temp2 = temp2->right;
        }
        else
            temp2 = temp2->left;
    }
    return;
}