#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>

using namespace std;

int main() {
    int nodesCount;
    cin >> nodesCount;

    unordered_map<int, unordered_set<int>> graph;
    for (int i = 0; i < nodesCount; ++i) {
        graph[i] = unordered_set<int>();
    }

    for (int i = 0; i < nodesCount - 1; ++i) {
        int from, to;
        cin >> from >> to;
        graph[from].insert(to);
        graph[to].insert(from);
    }

    vector<pair<int, int>> edgesToRemove;
    while (true) {
        edgesToRemove.clear();

        for (auto kvp : graph) {
            if (kvp.second.size() == 1) {
                int to = *kvp.second.begin();
                edgesToRemove.emplace_back(kvp.first, to);
            }
        }

        if (graph.size() == edgesToRemove.size() || edgesToRemove.empty()) {
            break;
        }

        for (auto edge : edgesToRemove) {
            graph.erase(edge.first);
            graph[edge.second].erase(edge.first);
        }
    }

    set<int> result;
    for (auto kvp : graph) {
        result.insert(kvp.first);
    }

    for (auto node : result) {
        cout << node << " ";
    }
}