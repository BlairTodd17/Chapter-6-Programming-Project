#include <iostream>
#include <iomanip>
using namespace std;

void displayTemperatureTable();
double fahrenheitToCelsius(double fahrenheit);

int main() {
    cout << "Fahrenheit to Celsius Temperature Table" << endl;
    cout << "------------------------------------" << endl;

    displayTemperatureTable();

    cout << "\nThank you for using the Celsius Temperature Table program!\n";
    return 0;
}

void displayTemperatureTable() {
    cout << setw(15) << "Fahrenheit" << setw(15) << "Celsius" << endl;
    cout << "------------------------------------" << endl;

    for (int fahrenheit = 0; fahrenheit <= 20; ++fahrenheit) {
        double celsius = fahrenheitToCelsius(fahrenheit);
        cout << setw(15) << fahrenheit << setw(15) << fixed << setprecision(2) << celsius << endl;
    }
}

double fahrenheitToCelsius(double fahrenheit) {
    return (5.0 / 9.0) * (fahrenheit - 32);
}
