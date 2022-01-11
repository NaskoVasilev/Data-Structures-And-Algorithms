#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    map<int, int> occur;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        numbers[i] = num;
        if (!occur.count(num)) {
            occur[num] = 0;
        }

        occur[num]++;
    }

    vector<int> first;
    vector<int> second;
    for (int i = 0; i < numbers.size(); ++i) {
        int num = numbers[i];
        if (!occur[num]) {
            continue;
        }

        if (occur[num] == 1) {
            first.push_back(num);
        } else {
            second.push_back(num);
            occur[num] = 0;
        }
    }

    for (auto num : first) {
        cout << num << " ";
    }

    for (auto num : second) {
        cout << num << " ";
    }
}