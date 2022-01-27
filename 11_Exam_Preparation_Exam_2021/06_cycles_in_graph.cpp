#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int from, to, cost;
};

bool edgeDescendingComparator(const Edge &first, const Edge &second) {
    return first.cost > second.cost;
}

int findRoot(vector<int> &parents, int node) {
    if (parents[node] == node) {
        return node;
    }

    parents[node] = findRoot(parents, parents[node]);
    return parents[node];
}

int kruskal(vector<Edge> &graph) {
    sort(graph.begin(), graph.end(), edgeDescendingComparator);

    vector<int> parents(graph.size());
    for (int i = 0; i < parents.size(); ++i) {
        parents[i] = i;
    }

    int answer = 0;
    for (const Edge &edge : graph) {
        int fromRoot = findRoot(parents, edge.from);
        int toRoot = findRoot(parents, edge.to);

        if (fromRoot != toRoot) {
            parents[fromRoot] = toRoot;
        } else {
            answer += edge.cost;
        }
    }

    return answer;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> graph;
    for (int i = 0; i < m; ++i) {
        int from, to, cost;
        cin >> from >> to >> cost;
        graph.push_back({from, to, cost});
    }

    cout << kruskal(graph);
}