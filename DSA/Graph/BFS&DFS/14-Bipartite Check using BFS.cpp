// https: // leetcode.com/problems/is-graph-bipartite/description/

//////////////////////////// DFS ///////////////////////////////////////////
bool dfs(vector<vector<int>> &g, vector<int> &v, int par, int node, int val)
{
    v[node] = val;
    for (int i = 0; i < g[node].size(); i++)
    {
        if (v[g[node][i]] == 0)
        {
            bool x = dfs(g, v, node, g[node][i], 3 - val);
            if (!x)
                return x;
        }
        else if (g[node][i] != par and v[g[node][i]] == val)
            return false;
    }
    return true;
}
bool isBipartiteDFS(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (!v[i] and !dfs(graph, v, -1, i, 1))
            return 0;
    }
    return 1;
}
////////////////// BFS //////////////////////
bool isBipartite(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> c(n, 0);
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (!c[i])
        {
            c[i] = 1;
            q.push(i);
            while (!q.empty())
            {
                int x = q.front();
                q.pop();
                for (int i = 0; i < graph[x].size(); i++)
                {
                    if (!c[graph[x][i]])
                    {
                        c[graph[x][i]] = 3 - c[x];
                        q.push(graph[x][i]);
                    }
                    else if (c[graph[x][i]] == c[x] and graph[x][i] != x)
                        return 0;
                }
            }
        }
    }
    return 1;
}