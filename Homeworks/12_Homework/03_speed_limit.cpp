#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct Edge {
    int from, to, speed;

    bool operator<(const Edge &other) {
        return this->speed < other.speed;
    }
};

int findRoot(int node, vector<int> &parents) {
    if (parents[node] == node) {
        return node;
    }

    parents[node] = findRoot(parents[node], parents);
    return parents[node];
}

void solve(int nodesCount, vector<Edge> &edges) {
    sort(edges.begin(), edges.end());
    int counter = 0;
    int bestSpeedDifference = INT32_MAX;
    int bestMinSpeed = 0;
    int bestMaxSpeed = 0;

    for (Edge &edge : edges) {
        int mstCount = 0;
        int maxSpeed = 0;
        vector<int> parents(nodesCount + 1);

        for (int i = 1; i < parents.size(); i++) {
            parents[i] = i;
        }

        for (int i = counter; i < edges.size(); i++) {
            int firstNodeRoot = findRoot(edges[i].from, parents);
            int secondNodeRoot = findRoot(edges[i].to, parents);

            if (firstNodeRoot != secondNodeRoot) {
                parents[firstNodeRoot] = secondNodeRoot;
                if (edges[i].speed > maxSpeed) {
                    maxSpeed = edges[i].speed;
                }

                mstCount++;
            }
        }


        int currentDifference = maxSpeed - edge.speed;
        if (mstCount == nodesCount - 1 && bestSpeedDifference > currentDifference) {
            bestSpeedDifference = currentDifference;
            bestMaxSpeed = maxSpeed;
            bestMinSpeed = edge.speed;
        }

        counter++;
    }

    cout << bestMinSpeed << " " << bestMaxSpeed;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int nodesCount, edgesCount;
    cin >> nodesCount >> edgesCount;

    vector<Edge> edges(edgesCount);
    for (int i = 0; i < edgesCount; i++) {
        cin >> edges[i].from >> edges[i].to >> edges[i].speed;
    }

    solve(nodesCount, edges);
}