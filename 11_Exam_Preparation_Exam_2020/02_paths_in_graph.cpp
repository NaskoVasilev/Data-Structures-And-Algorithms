#include <iostream>
#include <vector>

using namespace std;

const int NOT_VISITED = -1;

void dfs(vector<vector<int>> &graph, vector<int> &nodesByComponent, int node, int component) {
    nodesByComponent[node] = component;

    for (auto child : graph[node]) {
        if (nodesByComponent[child] == NOT_VISITED) {
            dfs(graph, nodesByComponent, child, component);
        }
    }
}

void findConnectedComponents(vector<vector<int>> &graph, vector<int> &nodesByComponent) {
    nodesByComponent = vector<int>(graph.size(), NOT_VISITED);
    int component = 0;
    for (int i = 1; i < graph.size(); ++i) {
        if (nodesByComponent[i] == NOT_VISITED) {
            dfs(graph, nodesByComponent, i, component);
            component++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; ++i) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    vector<int> nodesByComponent;
    findConnectedComponents(graph, nodesByComponent);

    int queriesCount;
    cin >> queriesCount;
    for (int i = 0; i < queriesCount; ++i) {
        int from, to;
        cin >> from >> to;

        printf("%d ", nodesByComponent[from] == nodesByComponent[to]);
    }
}