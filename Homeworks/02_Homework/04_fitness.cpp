#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Trainee {
    int identifier;
    double diameter;
    double time;
    double efficiency;
};

bool comparator(Trainee &first, Trainee &second) {
    if (first.efficiency == second.efficiency) {
        return first.diameter > second.diameter;
    }

    return first.efficiency > second.efficiency;
}

int main() {
    int n;
    cin >> n;

    vector<Trainee> trainees;
    for (int i = 0; i < n; ++i) {
        Trainee trainee;
        cin >> trainee.diameter;
        cin >> trainee.time;
        trainee.identifier = i + 1;
        trainee.efficiency = (trainee.diameter * trainee.diameter) / trainee.time;

        trainees.push_back(trainee);
    }

    sort(trainees.begin(), trainees.end(), comparator);

    for (Trainee &trainee : trainees) {
        cout << trainee.identifier << " ";
    }

    cout << endl;
}