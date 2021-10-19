#include <string>
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    string input;
    cin >> input;

    int steps = 0;
    int valleysCount = 0;
    bool inValley = false;
    for (int i = 0; i < n; i++) {
        char currentStep = input[i];

        if (steps == 0 && currentStep == 'D' && !inValley) {
            inValley = true;
        } else if (steps == -1 && currentStep == 'U' && inValley) {
            valleysCount++;
            inValley = false;
        }

        if (currentStep == 'U') {
            steps++;
        } else if (currentStep == 'D') {
            steps--;
        }
    }

    cout << valleysCount << endl;
}
