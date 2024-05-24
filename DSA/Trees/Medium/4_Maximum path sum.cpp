int maxPathSum(TreeNode *root)
{
    int maxi = INT_MIN;

    findMaxPathSum(root, maxi);
    return maxi;
}
int findMaxPathSum(TreeNode *root, int &maxi)
{
    if (root == NULL)
        return 0;

    int leftMaxPath = max(0, findMaxPathSum(root->left, maxi));
    int rightMaxPath = max(0, findMaxPathSum(root->right, maxi));

    maxi = max(maxi, leftMaxPath + rightMaxPath + root->val);

    return max(leftMaxPath, rightMaxPath) + root->val;
}