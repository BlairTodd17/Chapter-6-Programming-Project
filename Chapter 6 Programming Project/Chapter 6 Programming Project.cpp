#include <iostream>
#include <iomanip>
using namespace std;

int getNumberOfRooms();
double getPaintPrice();
double getWallSpace(int roomNumber);
double calculatePaintGallons(double totalWallSpace);
double calculateLaborHours(double totalWallSpace);
double calculatePaintCost(double gallons, double pricePerGallon);
double calculateLaborCost(double laborHours);
void displayCostSummary(double gallons, double laborHours, double paintCost, double laborCost);

const double WALL_SPACE_PER_GALLON = 110.0;
const double HOURS_PER_GALLON = 8.0;
const double LABOR_COST_PER_HOUR = 25.0;

int main() {
    int numberOfRooms = getNumberOfRooms();
    double pricePerGallon = getPaintPrice();

    double totalWallSpace = 0.0;
    for (int i = 1; i <= numberOfRooms; i++) {
        totalWallSpace += getWallSpace(i);
    }

    double gallonsOfPaint = calculatePaintGallons(totalWallSpace);
    double laborHours = calculateLaborHours(totalWallSpace);
    double paintCost = calculatePaintCost(gallonsOfPaint, pricePerGallon);
    double laborCost = calculateLaborCost(laborHours);

    displayCostSummary(gallonsOfPaint, laborHours, paintCost, laborCost);

    return 0;
}

int getNumberOfRooms() {
    int rooms;
    do {
        cout << "Enter the number of rooms to be painted: ";
        cin >> rooms;
        if (rooms < 1) {
            cout << "Number of rooms must be at least 1. Please try again.\n";
        }
    } while (rooms < 1);
    return rooms;
}

double getPaintPrice() {
    double price;
    do {
        cout << "Enter the price of paint per gallon (minimum $10.00): ";
        cin >> price;
        if (price < 10.0) {
            cout << "Price of paint must be at least $10.00. Please try again.\n";
        }
    } while (price < 10.0);
    return price;
}

double getWallSpace(int roomNumber) {
    double wallSpace;
    do {
        cout << "Enter the wall space in square feet for room " << roomNumber << ": ";
        cin >> wallSpace;
        if (wallSpace < 0.0) {
            cout << "Wall space cannot be negative. Please try again.\n";
        }
    } while (wallSpace < 0.0);
    return wallSpace;
}

double calculatePaintGallons(double totalWallSpace) {
    return ceil(totalWallSpace / WALL_SPACE_PER_GALLON);
}

double calculateLaborHours(double totalWallSpace) {
    return (totalWallSpace / WALL_SPACE_PER_GALLON) * HOURS_PER_GALLON;
}

double calculatePaintCost(double gallons, double pricePerGallon) {
    return gallons * pricePerGallon;
}

double calculateLaborCost(double laborHours) {
    return laborHours * LABOR_COST_PER_HOUR;
}

void displayCostSummary(double gallons, double laborHours, double paintCost, double laborCost) {
    double totalCost = paintCost + laborCost;

    cout << fixed << setprecision(2);
    cout << "\nPaint Job Summary:\n";
    cout << "Gallons of paint required: " << gallons << endl;
    cout << "Hours of labor required: " << laborHours << endl;
    cout << "Cost of paint: $" << paintCost << endl;
    cout << "Labor charges: $" << laborCost << endl;
    cout << "Total cost of the paint job: $" << totalCost << endl;
}