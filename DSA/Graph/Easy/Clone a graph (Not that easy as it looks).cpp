class Solution
{
private:
    unordered_map<Node *, Node *> visited;

public:
    Node *cloneGraph(Node *node)
    {
        if (node == nullptr)
        {
            return nullptr;
        }
        if (visited.find(node) != visited.end())
        {                         // 1st hash calculation and method call
            return visited[node]; // 2nd hash calculation and method call
        }
        Node *clone = new Node(node->val);
        visited[node] = clone;
        for (Node *neighbor : node->neighbors)
        {
            clone->neighbors.push_back(cloneGraph(neighbor));
        }
        return clone;
    }
};

class Solution
{
private:
    unordered_map<Node *, Node *> visited;

public:
    Node *cloneGraph(Node *node)
    {
        if (node == nullptr)
        {
            return nullptr;
        }
        Node *&clone = visited[node]; // slightly optimized here, only one time hash calculation and method call
        if (clone != nullptr)
        {
            return clone;
        }
        clone = new Node(node->val);
        for (Node *neighbor : node->neighbors)
        {
            clone->neighbors.push_back(cloneGraph(neighbor));
        }
        return clone;
    }
};