// https : // www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

bool detect(int src, vector<int> adj[], int vis[])
{
    vis[src] = 1;

    queue<pair<int, int>> q;

    q.push({src, -1});

    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (auto adjacentNode : adj[node])
        {
            if (!vis[adjacentNode])
            {
                vis[adjacentNode] = 1;
                q.push({adjacentNode, node});
            }
            // if adjacent node is visited and is not it's own parent node
            else if (parent != adjacentNode)
            {
                // yes it is a cycle
                return true;
            }
        }
    }
    return false;
}

bool isCycle(int V, vector<int> adj[])
{
    // Code here
    int vis[V] = {0};
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (detect(i, adj, vis))
                return true;
        }
    }

    return false;
}