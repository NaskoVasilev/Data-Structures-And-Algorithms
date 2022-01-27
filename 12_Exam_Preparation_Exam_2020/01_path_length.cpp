#include <iostream>
#include <vector>

using namespace std;

int findPathLength(vector<vector<int>> &graph, vector<int> &path) {
    int from = path[0];
    int pathLength = 0;
    for (int i = 1; i < path.size(); ++i) {
        int to = path[i];
        if (graph[from][to] == 0) {
            return -1;
        }

        pathLength += graph[from][to];
        from = to;
    }

    return pathLength;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n, vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from][to] = cost;
        graph[to][from] = cost;
    }

    int k;
    cin >> k;
    vector<int> path(k);
    for (int i = 0; i < k; ++i) {
        cin >> path[i];
    }

    cout << findPathLength(graph, path);
}