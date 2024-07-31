// https : // www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

bool dfs(int node, int parent, int vis[], vector<int> adj[])
{
    vis[node] = 1;

    for (auto adjacentNode : adj[node])
    {
        if (!vis[adjacentNode])
        {
            if (dfs(adjacentNode, node, vis, adj) == true)
                return true;
        }
        // if adjacent node is visited and is not it's own parent node
        else if (parent != adjacentNode)
        {
            // yes it is a cycle
            return true;
        }
    }
    return false;
}

bool isCycle(int V, vector<int> adj[])
{
    // Code here
    int vis[V] = {0};
    // for graph with connected components
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, -1, vis, adj) == true)
                return true;
        }
    }
    return false;
}