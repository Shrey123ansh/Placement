Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
Output: [7,4,1]
Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.
Example 2:

Input: root = [1], target = 1, k = 3
Output: []


void parents(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &parent){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            if(node->left){
                parent[node->left]=node;
                q.push(node->left);
            }
            if(node->right){
                parent[node->right]=node;
                q.push(node->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent;
        parents(root,parent);
        unordered_map<TreeNode*,int> vis;
        queue<TreeNode*> q;
        q.push(target);
        vis[target]=1;
        int lvl=0;
        while(!q.empty()){
            int size=q.size();
            if(lvl==k)break;
            lvl++;
            for(int i=0;i<size;i++){
                auto node=q.front();
                q.pop();
                if(node->left && !vis[node->left]){
                    q.push(node->left);
                    vis[node->left]=1;
                }
                if(node->right && !vis[node->right]){
                    q.push(node->right);
                    vis[node->right]=1;
                }
                if(parent[node] && !vis[parent[node]]){
                    q.push(parent[node]);
                    vis[parent[node]]=1;
                }
            }
        }
        vector<int> ans;
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            ans.push_back(node->val);
        }
        return ans;
    }return ans;
}