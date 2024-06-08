vector<int> mp;
void traveral(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    traveral(root->left);
    mp.push_back(root->val);
    traveral(root->right);
}
bool findTarget(TreeNode *root, int k)
{
    traveral(root);
    map<int, int> fin;

    for (int i = 0; i < mp.size(); i++)
    {
        fin.insert({i, mp[i]});
    }
    for (int i = 0; i < mp.size(); i++)
    {
        int x = mp[i];
        int target = k - x;
        for (int j = 0; j < mp.size(); j++)
        {
            if (mp[j] == target && i != j)
            {
                return true;
            }
        }
    }
    return false;
}

/////////////////////////////////OR/////////////////////////////////////////

void inorder(TreeNode *root, vector<int> &t)
{
    if (root)
    {
        inorder(root->left, t);
        t.push_back(root->val);
        inorder(root->right, t);
    }
}

bool findTarget(TreeNode *root, int k)
{
    vector<int> t;
    inorder(root, t);
    int i = 0;
    int j = t.size() - 1;
    while (i < j)
    {
        int temp = t[i] + t[j];
        if (temp == k)
            return true;
        if (temp < k)
            i++;
        else
            j--;
    }
    return false;
}

/////////////////////////////////OR/////////////////////////////////////////

bool solve(TreeNode *root, unordered_map<int, int> &mp, int &k)
{
    

    // int dif=abs(k-root->val);
    if (root == nullptr)
        return 0;
    if (mp.find(k - root->val) != mp.end())
    {
        return true;
    }
    mp[root->val]++;
    return solve(root->right, mp, k) || solve(root->left, mp, k);
}
bool findTarget(TreeNode *root, int k)
{
    unordered_map<int, int> mp;
    if (!root)
        return 0;
    return solve(root, mp, k);
}