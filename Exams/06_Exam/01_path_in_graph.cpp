#include<iostream>
#include<vector>
#include <unordered_set>

using namespace std;

void dfs(vector<vector<int>> &graph, int node, vector<bool> &visited, vector<int> &traversedNodes) {
    if (!visited[node]) {
        visited[node] = true;
        for (int child : graph[node]) {
            dfs(graph, child, visited, traversedNodes);
        }

        traversedNodes.push_back(node);
    }
}

void findGraphConnectedComponents(vector<vector<int>> &graph, vector<int> &nodesByComponents) {
    int count = 0;

    vector<bool> visited(graph.size());
    vector<int> traversedNodes;
    for (int node = 0; node < graph.size(); node++) {
        if (!visited[node]) {
            dfs(graph, node, visited, traversedNodes);
            count++;
            for (int traversedNode : traversedNodes) {
                nodesByComponents[traversedNode] = count;
            }

            traversedNodes.clear();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int verticesCount, edgesCount;
    cin >> verticesCount >> edgesCount;

    vector<vector<int>> graph(verticesCount + 1, vector<int>());

    for (int i = 0; i < edgesCount; ++i) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    int queriesCount;
    cin >> queriesCount;

    vector<int> nodeByComponent(graph.size());
    findGraphConnectedComponents(graph, nodeByComponent);

    for (int i = 0; i < queriesCount; ++i) {
        int sourceNode, destinationNode;
        cin >> sourceNode >> destinationNode;
        if (nodeByComponent[sourceNode] == nodeByComponent[destinationNode]) {
            printf("1 ");
        } else {
            printf("0 ");
        }
    }
}