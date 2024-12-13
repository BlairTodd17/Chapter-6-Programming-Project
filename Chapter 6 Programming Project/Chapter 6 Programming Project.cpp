#include <iostream>
#include <string>
using namespace std;

int getAccidents(const string& region);
string findSafestRegion(int north, int south, int east, int west, int central);

int main() {
    int north, south, east, west, central;

    north = getAccidents("North");
    south = getAccidents("South");
    east = getAccidents("East");
    west = getAccidents("West");
    central = getAccidents("Central");

    string safestRegion = findSafestRegion(north, south, east, west, central);
    cout << "\nThe safest region is: " << safestRegion << "\n";

    return 0;
}

int getAccidents(const string& region) {
    int accidents;
    do {
        cout << "Enter the number of reported accidents in the " << region << " region: ";
        cin >> accidents;
        if (accidents < 0) {
            cout << "Number of accidents cannot be negative. Please try again.\n";
        }
    } while (accidents < 0);
    return accidents;
}

string findSafestRegion(int north, int south, int east, int west, int central) {
    int minAccidents = north;
    string safest = "North";

    if (south < minAccidents) {
        minAccidents = south;
        safest = "South";
    }
    if (east < minAccidents) {
        minAccidents = east;
        safest = "East";
    }
    if (west < minAccidents) {
        minAccidents = west;
        safest = "West";
    }
    if (central < minAccidents) {
        minAccidents = central;
        safest = "Central";
    }

    return safest;
}
