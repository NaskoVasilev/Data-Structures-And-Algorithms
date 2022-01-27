#include <iostream>
#include <list>
#include <unordered_set>

using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_set<int> occurrences;
    int maxLength = 1;
    int currentLength = 0;
    list<int> q;
    for (int i = 0; i < n; ++i) {
        int number;
        cin >> number;

        if (occurrences.count(number)) {
            if (currentLength > maxLength) {
                maxLength = currentLength;
            }

            while (q.front() != number) {
                occurrences.erase(q.front());
                q.pop_front();
            }

            q.pop_front();
            currentLength = q.size();
        } else {
            occurrences.insert(number);
        }

        currentLength++;
        q.push_back(number);
    }

    cout << max(currentLength, maxLength);
}