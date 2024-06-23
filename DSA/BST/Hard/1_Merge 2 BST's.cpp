stack<TreeNode *> st;

private:
void pushall(TreeNode *root)
{
    while (root)
    {
        st.push(root);
        root = root->left;
    }
}

public:
BSTIterator(TreeNode *root)
{
    pushall(root);
}

int next()
{
    TreeNode *tmp = st.top();
    st.pop();
    pushall(tmp->right);
    return tmp->val;
}

bool hasNext()
{
    return !st.empty();
}
}
;
