Input:      
          1
        /   \
      2      3
    /  \      \
   4    5      6
       / \      \
      7   8      9
                   \
                   10
Target Node = 8
Output: 7
Explanation: If leaf with the value 
8 is set on fire. 
After 1 sec: 5 is set on fire.
After 2 sec: 2, 7 are set to fire.
After 3 sec: 4, 1 are set to fire.
After 4 sec: 3 is set to fire.
After 5 sec: 6 is set to fire.
After 6 sec: 9 is set to fire.
After 7 sec: 10 is set to fire.
It takes 7s to burn the complete tree.


Input:      
          1
        /   \
      2      3
    /  \      \
   4    5      7
  /    / 
 8    10
Target Node = 10
Output: 5


class Solution {
    
    void getAdjList(map<int, vector<int>>&adj, Node* root){
        if(root==NULL){
            return ;
        }
        
        if(root->left!=NULL){
            adj[root->data].push_back(root->left->data);
            adj[root->left->data].push_back(root->data);
        }
        getAdjList(adj, root->left);
        if(root->right!=NULL){
            adj[root->data].push_back(root->right->data);
            adj[root->right->data].push_back(root->data);
        }
        getAdjList(adj, root->right);
    }
    
  public:
    int minTime(Node* root, int target) 
    {
        map<int, vector<int>>adj;
        getAdjList(adj, root);
        
        map<int, int>vis;
        queue<pair<int, int>>q;
        q.push({target, 0});
        int time = 0;
        vis[target]=1;
        
        while(!q.empty()){
            int node = q.front().first;
            int currTime = q.front().second;
            q.pop();
            time=max(time, currTime);
            
            for(auto ele:adj[node]){
                if(!vis[ele]){
                    q.push({ele, currTime+1});
                    vis[ele]=1;
                }
            }
        }
        return time;
        
    }
};