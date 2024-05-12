#include <iostream>
#include <cmath>

using namespace std;

void Midpoint(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int d = 2 * dy - dx;
    int incrE = 2 * dy;
    int incrNE = 2 * (dy - dx);
    int x = x1, y = y1;
    cout << "Midpoint Line Drawing Algorithm:" << endl;
    cout << "(" << x1 << ", " << y1 << ") -> (" << x2 << ", " << y2 << ")" << endl;
    cout << "Points on the line:" << endl;
    cout << "(" << x << ", " << y << ")" << endl;
    while (x < x2) {
        if (d <= 0) {
            d += incrE;
            x++;
        }
        else {
            d += incrNE;
            x++;
            y++;
        }
        cout << "(" << x << ", " << y << ")" << endl;
    }
}

int main() {
    int x1, y1, x2, y2;
    cout << "Enter coordinates of first point (x1 y1): ";
    cin >> x1 >> y1;
    cout << "Enter coordinates of second point (x2 y2): ";
    cin >> x2 >> y2;
    Midpoint(x1, y1, x2, y2);
    return 0;
}