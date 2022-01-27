#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void addEdge(unordered_map<int, vector<int>> &graph, int from, int to) {
    if (!graph.count(from)) {
        graph[from] = vector<int>();
    }

    graph[from].push_back(to);
}

void dfs(unordered_map<int, vector<int>> &graph, int node, unordered_set<int> &visited) {
    visited.insert(node);
    for (int child : graph[node]) {
        if (!visited.count(child)) {
            dfs(graph, child, visited);
        }
    }
}

int isConnected(unordered_map<int, vector<int>> &graph) {
    unordered_set<int> visited;
    int count = 0;
    for (auto &kvp : graph) {
        if (!kvp.second.empty() && !visited.count(kvp.first)) {
            if (count == 1) {
                return false;
            }

            dfs(graph, kvp.first, visited);
            count++;
        }
    }

    return true;
}

string getEulerianProperties(unordered_map<int, vector<int>> &graph) {
    if (!isConnected(graph)) {
        return "none";
    }

    int oddVertices = 0;
    for (auto &kvp : graph) {
        if (kvp.second.size() % 2 != 0) {
            oddVertices++;
        }
    }

    if (oddVertices == 0) {
        return "ecycle";
    }

    return oddVertices == 2 ? "epath" : "none";
}

int main() {
    int queries;
    cin >> queries;
    vector<string> results;

    for (int i = 0; i < queries; ++i) {
        int nodesCount, edgesCount;
        cin >> nodesCount >> edgesCount;

        int maxNode = -1;
        unordered_map<int, vector<int>> graph;
        for (int j = 0; j < edgesCount; ++j) {
            int from, to;
            cin >> from >> to;
            addEdge(graph, from, to);
            addEdge(graph, to, from);
        }

        if(graph.size() != nodesCount) {
            results.push_back("none");
        }
        else {
            results.push_back(getEulerianProperties(graph));
        }
    }

    for(auto result : results) {
        cout << result << endl;
    }
}