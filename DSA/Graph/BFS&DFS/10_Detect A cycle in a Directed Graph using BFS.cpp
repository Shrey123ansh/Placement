// https : // leetcode.com/problems/course-schedule/solutions/

bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{

    vector<int> adj[numCourses];
    vector<int> indegree(numCourses);

    for (int i = 0; i < prerequisites.size(); i++)
    {
        adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        indegree[prerequisites[i][1]]++;
    }

    queue<int> q;
    for (int i = 0; i < numCourses; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    int c = q.size();
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (auto y : adj[x])
        {
            indegree[y]--;
            if (indegree[y] == 0)
            {
                q.push(y);
                c++;
            }
        }
    }
    if (c != numCourses)
        return false;
    return true;
}