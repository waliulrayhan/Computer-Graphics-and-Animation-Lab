#include <iostream>
#include <cmath>

using namespace std;

void MidpointCircle(int radius) {
    int x = 0;
    int y = radius;
    int d = 1 - radius;
    int deltaE = 3;
    int deltaSE = -2 * radius + 5;

    cout << "Midpoint Circle Drawing Algorithm:" << endl;
    cout << "Radius: " << radius << endl;
    cout << "Points on the circle:" << endl;

    while (x <= y) {
        cout << "(" << x << ", " << y << ")" << endl;
        cout << "(" << -x << ", " << y << ")" << endl;
        cout << "(" << x << ", " << -y << ")" << endl;
        cout << "(" << -x << ", " << -y << ")" << endl;
        cout << "(" << y << ", " << x << ")" << endl;
        cout << "(" << -y << ", " << x << ")" << endl;
        cout << "(" << y << ", " << -x << ")" << endl;
        cout << "(" << -y << ", " << -x << ")" << endl;

        if (d < 0) {
            d += deltaE;
            deltaE += 2;
            deltaSE += 2;
        } else {
            d += deltaSE;
            deltaE += 2;
            deltaSE += 4;
            y--;
        }
        x++;
    }
}

int main() {
    int radius;
    cout << "Enter radius of circle: ";
    cin >> radius;
    MidpointCircle(radius);
    return 0;
}