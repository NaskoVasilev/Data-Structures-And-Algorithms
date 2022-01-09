#include<iostream>
#include<vector>

using namespace std;

struct Edge {
    int from, to;
};

int findRoot(int node, vector<int> &parents) {
    if (parents[node] == node) {
        return node;
    }

    parents[node] = findRoot(parents[node], parents);
    return parents[node];
}

void solve(int nodesCount, vector<Edge> &edges, int queriesCount, vector<int> &results) {
    vector<int> parents(nodesCount + 1);
    for (int i = 1; i < parents.size(); i++) {
        parents[i] = i;
    }

    for (auto &edge: edges) {
        int firstNodeRoot = findRoot(edge.from, parents);
        int secondNodeRoot = findRoot(edge.to, parents);

        if (firstNodeRoot != secondNodeRoot) {
            parents[firstNodeRoot] = secondNodeRoot;
        }
    }


    for (int i = 0; i < queriesCount; ++i) {
        int queryType, from, to;
        cin >> queryType >> from >> to;
        int firstRoot = findRoot(from, parents);
        int secondRoot = findRoot(to, parents);

        if (queryType == 1) {
            results.push_back(firstRoot == secondRoot);
        } else if (firstRoot != secondRoot) {
            parents[firstRoot] = secondRoot;
        }
    }
}

int main() {
    int nodesCount, edgesCount;
    cin >> nodesCount >> edgesCount;

    vector<Edge> edges(edgesCount);
    for (int i = 0; i < edges.size(); i++) {
        Edge edge{};
        cin >> edge.from >> edge.to;
        edges[i] = edge;
    }

    int queriesCount;
    cin >> queriesCount;
    vector<int> results;
    solve(nodesCount, edges, queriesCount, results);

    for (int result : results) {
        cout << result;
    }
}