#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void dfs(vector<vector<int>> &graph, vector<bool> &visited, int node) {
    visited[node] = true;

    for (auto child : graph[node]) {
        if (!visited[child]) {
            dfs(graph, visited, child);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int testsCount;
    cin >> testsCount;

    vector<int> results;
    for (int i = 0; i < testsCount; ++i) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> graph(n);
        for (int j = 0; j < m; ++j) {
            int from, to;
            cin >> from >> to;
            graph[from].push_back(to);
            graph[to].push_back(from);
        }

        int components = 0;
        vector<bool> visited(n, false);
        for (int node = 0; node < graph.size(); ++node) {
            if (!visited[node]) {
                dfs(graph, visited, node);
                components++;
            }
        }

        results.push_back(components);
    }

    for (auto result : results) {
        printf("%d ", result);
    }
}