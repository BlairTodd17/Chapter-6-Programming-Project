#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

=void getScores(double scores[], int size);
double calculateFinalScore(double scores[], int size);
double findHighest(double scores[], int size);
double findLowest(double scores[], int size);

const int NUM_JUDGES = 5;

int main() {
    double scores[NUM_JUDGES];

    getScores(scores, NUM_JUDGES);

    double finalScore = calculateFinalScore(scores, NUM_JUDGES);

    cout << fixed << setprecision(2);
    cout << "\nThe contestant's final score is: " << finalScore << endl;

    return 0;
}

void getScores(double scores[], int size) {
    for (int i = 0; i < size; i++) {
        do {
            cout << "Enter score for judge " << (i + 1) << " (0-10): ";
            cin >> scores[i];
            if (scores[i] < 0.0 || scores[i] > 10.0) {
                cout << "Invalid score. Scores must be between 0 and 10. Please try again.\n";
            }
        } while (scores[i] < 0.0 || scores[i] > 10.0);
    }
}

double calculateFinalScore(double scores[], int size) {
    double highest = findHighest(scores, size);
    double lowest = findLowest(scores, size);
    double sum = 0.0;

    for (int i = 0; i < size; i++) {
        sum += scores[i];
    }

    sum -= (highest + lowest);

    return sum / (size - 2);
}

double findHighest(double scores[], int size) {
    double highest = scores[0];
    for (int i = 1; i < size; i++) {
        if (scores[i] > highest) {
            highest = scores[i];
        }
    }
    return highest;
}

double findLowest(double scores[], int size) {
    double lowest = scores[0];
    for (int i = 1; i < size; i++) {
        if (scores[i] < lowest) {
            lowest = scores[i];
        }
    }
    return lowest;
}