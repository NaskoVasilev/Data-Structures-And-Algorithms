#include<iostream>
#include<vector>

using namespace std;

void dfs(vector<vector<int>> &graph, int node, vector<bool> &visited) {
    if (!visited[node]) {
        visited[node] = true;
        for (int child : graph[node]) {
            dfs(graph, child, visited);
        }
    }
}

int findGraphConnectedComponents(vector<vector<int>> &graph) {
    int count = 0;
    vector<bool> visited(graph.size());
    for (int node = 0; node < graph.size(); node++) {
        if (!visited[node]) {
            dfs(graph, node, visited);
            count++;
        }
    }

    return count;
}

int main() {
    int tests;
    cin >> tests;

    for (int i = 0; i < tests; ++i) {
        int verticesCount, edgesCount;
        cin >> verticesCount >> edgesCount;
        vector<vector<int>> graph(verticesCount, vector<int>());

        for (int i = 0; i < edgesCount; ++i) {
            int from, to;
            cin >> from >> to;
            graph[from].push_back(to);
            graph[to].push_back(from);
        }

        cout << findGraphConnectedComponents(graph) << " ";
    }
}