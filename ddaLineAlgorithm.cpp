#include <iostream>
#include <cmath>

using namespace std;

void DDA(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = max(abs(dx), abs(dy));
    float xIncrement = dx / (float)steps;
    float yIncrement = dy / (float)steps;

    float x = x1, y = y1;
    cout << "DDA Line Drawing Algorithm:" << endl;
    cout << "(" << x1 << ", " << y1 << ") -> (" << x2 << ", " << y2 << ")" << endl;
    cout << "Points on the line:" << endl;
    for (int i = 0; i <= steps; i++) {
        cout << "(" << round(x) << ", " << round(y) << ")" << endl;
        x += xIncrement;
        y += yIncrement;
    }
}

int main() {
    int x1, y1, x2, y2;
    cout << "Enter coordinates of first point (x1 y1): ";
    cin >> x1 >> y1;
    cout << "Enter coordinates of second point (x2 y2): ";
    cin >> x2 >> y2;
    DDA(x1, y1, x2, y2);
    return 0;
}