#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> first(n);
    for (int i = 0; i < n; ++i) {
        cin >> first[i];
    }

    vector<int> second(m);
    for (int i = 0; i < m; ++i) {
        cin >> second[i];
    }

    sort(first.begin(), first.end());

    for (auto number : second) {
        auto numberPointer = lower_bound(first.begin(), first.end(), number);
        int smallerNumbersCount = numberPointer - first.begin();
        printf("%d ", smallerNumbersCount);
    }
}