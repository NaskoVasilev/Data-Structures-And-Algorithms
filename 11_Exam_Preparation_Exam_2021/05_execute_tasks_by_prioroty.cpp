#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int queriesPerGroup, interval, groupsCount;
    cin >> queriesPerGroup >> interval >> groupsCount;
    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> results;
    for (int i = 1; i <= n; ++i) {
        if (groupsCount == 0) {
            break;
        }

        int query;
        cin >> query;

        pq.push(query);

        if (i % interval == 0) {
            for (int j = 0; j < queriesPerGroup; ++j) {
                results.push_back(pq.top());
                pq.pop();
            }

            groupsCount--;
        }

    }

    for (int i = 0; i < groupsCount; ++i) {
        for (int j = 0; j < queriesPerGroup; ++j) {
            results.push_back(pq.top());
            pq.pop();
        }
    }

    for (int result : results) {
        printf("%d ", result);
    }
}