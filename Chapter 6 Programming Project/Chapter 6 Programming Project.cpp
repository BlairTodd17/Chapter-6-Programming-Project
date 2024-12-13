#include <iostream>
#include <iomanip>
using namespace std;


void getDimensions(double& length, double& width);
double calculatePerimeter(double length, double width);
double calculateArea(double length, double width);
bool processAnotherRectangle();

int main() {
    double length, width;

    do {
        
        getDimensions(length, width);

        
        double perimeter = calculatePerimeter(length, width);
        double area = calculateArea(length, width);

        cout << fixed << setprecision(2);
        cout << "\nRectangle Properties:\n";
        cout << "Perimeter: " << perimeter << "\n";
        cout << "Area: " << area << "\n";

    } while (processAnotherRectangle());

    cout << "\nThank you for using the Rectangle Properties program!\n";
    return 0;
}


void getDimensions(double& length, double& width) {
    do {
        cout << "Enter the length of the rectangle: ";
        cin >> length;
        if (length < 0) {
            cout << "Length cannot be negative. Please try again.\n";
        }
    } while (length < 0);

    do {
        cout << "Enter the width of the rectangle: ";
        cin >> width;
        if (width < 0) {
            cout << "Width cannot be negative. Please try again.\n";
        }
    } while (width < 0);
}

double calculatePerimeter(double length, double width) {
    return 2 * (length + width);
}


double calculateArea(double length, double width) {
    return length * width;
}

bool processAnotherRectangle() {
    char choice;
    cout << "\nDo you want to process another rectangle? (Y/N): ";
    cin >> choice;
    return (choice == 'Y' || choice == 'y');
}
