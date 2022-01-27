#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void executeQueries(vector<int> &nums, vector<int> &queries) {
    for (int query : queries) {
        int startIndex = lower_bound(nums.begin(), nums.end(), query) - nums.begin();
        int endIndex = upper_bound(nums.begin(), nums.end(), query) - nums.begin() - 1;
        if (endIndex < startIndex) {
            printf("%d\n", startIndex);
        } else {
            printf("%d %d\n", startIndex, endIndex);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int queriesCount;
    cin >> queriesCount;
    vector<int> queries(queriesCount);
    for (int i = 0; i < queriesCount; ++i) {
        cin >> queries[i];
    }

    executeQueries(nums, queries);
}