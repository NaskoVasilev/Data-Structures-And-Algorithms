#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

struct Edge {
    int from, to, index;
    long long cost, profit;

    bool operator<(const Edge &other) {
        if (this->cost == other.cost) {
            return this->profit > other.profit;
        }

        return this->cost < other.cost;
    }
};

int findRoot(int node, vector<int> &parents) {
    if (parents[node] == node) {
        return node;
    }

    parents[node] = findRoot(parents[node], parents);
    return parents[node];
}

void kruskal(int nodesCount, vector<Edge> &edges, set<int> &results) {
    sort(edges.begin(), edges.end());

    vector<int> parents(nodesCount + 1);
    for (int i = 1; i < parents.size(); i++) {
        parents[i] = i;
    }

    for (Edge &edge : edges) {
        int firstNodeRoot = findRoot(edge.from, parents);
        int secondNodeRoot = findRoot(edge.to, parents);

        if (firstNodeRoot != secondNodeRoot) {
            parents[firstNodeRoot] = secondNodeRoot;

            results.insert(edge.index);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int nodesCount, edgesCount;
    cin >> nodesCount >> edgesCount;

    vector<Edge> edges(edgesCount);
    for (int i = 0; i < edgesCount; i++) {
        cin >> edges[i].from >> edges[i].to >> edges[i].cost >> edges[i].profit;
        edges[i].index = i + 1;
    }

    set<int> results;

    kruskal(nodesCount, edges, results);

    for (auto index : results) {
        printf("%d\n", index);
    }
}