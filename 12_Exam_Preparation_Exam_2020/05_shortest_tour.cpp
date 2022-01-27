#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int bfs(vector<vector<int>> &graph, int startNode, int destinationNode, set<int>& nonTraversalNodes) {
    vector<int> distances(graph.size(), INT32_MAX);
    distances[startNode] = 0;
    queue<int> q;
    q.push(startNode);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        if(current == destinationNode) {
            return distances[destinationNode];
        }

        for (auto child : graph[current]) {
            if (!nonTraversalNodes.count(child) && distances[child] > distances[current] + 1) {
                distances[child] = distances[current] + 1;
                q.push(child);
            }
        }
    }

    return distances[destinationNode];
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; ++i) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
    }

    int k;
    cin >> k;
    vector<int> attractions(k);
    set<int> nonTraversalNodes;
    for (int i = 0; i < k; ++i) {
        cin >> attractions[i];
        nonTraversalNodes.insert(attractions[i]);
    }

    int pathLength = 0;
    int startNode = attractions[0];
    nonTraversalNodes.erase(startNode);

    for (int i = 1; i < attractions.size(); ++i) {
        int destinationNode = attractions[i];
        nonTraversalNodes.erase(destinationNode);

        int currentLength = bfs(graph, startNode, destinationNode, nonTraversalNodes);

        if (currentLength == INT32_MAX) {
            cout << -1;
            return 0;
        } else {
            pathLength += currentLength;
        }

        startNode = destinationNode;
    }

    cout << pathLength;
}