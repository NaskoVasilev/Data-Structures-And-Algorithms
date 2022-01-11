#include <iostream>
#include <map>
#include <vector>
#include <unordered_set>

using namespace std;

struct Edge {
    int to;
    int weight;
};

bool isValidPath(vector<vector<Edge>> &graph, unordered_set<int> &invalidWeights, vector<int> &path) {
    if (path.empty()) {
        return false;
    }

    for (int i = 1; i < path.size(); ++i) {
        int from = path[i - 1];
        int to = path[i];
        bool hasValidEdge = false;
        for (int j = 0; j < graph[from].size(); ++j) {
            Edge edge = graph[from][j];
            if (edge.to == to && !invalidWeights.count(edge.weight)) {
                hasValidEdge = true;
                break;
            }
        }

        if (!hasValidEdge) {
            return false;
        }
    }

    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> graph(n);
    for (int i = 0; i < m; ++i) {
        int from;
        Edge edge;
        cin >> from;
        cin >> edge.to >> edge.weight;
        graph[from].push_back(edge);
    }

    int k;
    cin >> k;
    unordered_set<int> invalidWeights;
    for (int i = 0; i < k; ++i) {
        int num;
        cin >> num;
        invalidWeights.insert(num);
    }

    int queries;
    cin >> queries;
    for (int i = 0; i < queries; ++i) {
        int pathLength;
        cin >> pathLength;
        vector<int> path(pathLength);
        for (int j = 0; j < pathLength; ++j) {
            cin >> path[j];
        }

        cout << isValidPath(graph, invalidWeights, path);
    }
}