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

    arr.push_back(root->val);
    preorder(root->left, arr);
    preorder(root->right, arr);
}

///////////OR////////////

vector<int> preorderTraversal(TreeNode *root)
{

    vector<int> ans;
    if (!root)
        return ans;

    stack<TreeNode *> st;
    st.push(root);
    while (!st.empty())
    {
        TreeNode *node = st.top();
        st.pop();

        ans.push_back(node->val);
        if (node->right)
            st.push(node->right);
        if (node->left)
            st.push(node->left);
    }
    return ans;
}