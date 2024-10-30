#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include <cmath>

using namespace std;

int x_start, y_start, x_end, y_end;  // Global variables to store input coordinates

void drawGrid() {
    glColor3f(0.0, 0.0, 0.0);  // Set grid color to black
    glBegin(GL_LINES);

    // Draw vertical grid lines
    for (int i = 0; i <= 20; i++) {
        glVertex2f(i, 0);  // Vertical line from (i, 0) to (i, 20)
        glVertex2f(i, 20);
    }

    // Draw horizontal grid lines
    for (int i = 0; i <= 20; i++) {
        glVertex2f(0, i);  // Horizontal line from (0, i) to (20, i)
        glVertex2f(20, i);
    }

    glEnd();
}

void MidpointLine(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int d = 2 * dy - dx;
    int incrE = 2 * dy;
    int incrNE = 2 * (dy - dx);
    int x = x1, y = y1;

    // Print the initial points and the points on the line in console
    cout << "(" << x1 << ", " << y1 << ") -> (" << x2 << ", " << y2 << ")" << endl;
    cout << "Points on the line:" << endl;

    glColor3f(1.0, 0.0, 0.0);  // Set color for the points (red)
    glBegin(GL_POINTS);

    // Plot the first point and print it in the console
    glVertex2i(x, y);
    cout << "(" << x << ", " << y << ")" << endl;

    while (x < x2) {
        if (d <= 0) {
            d += incrE;
            x++;
        } else {
            d += incrNE;
            x++;
            y++;
        }
        glVertex2i(x, y);  // Plot the points on the line
        cout << "(" << x << ", " << y << ")" << endl;  // Output points to the console
    }

    glEnd();
    glFlush();  // Flush the drawing to the window
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);  // Clear the display window
    drawGrid();  // Draw the grid
    MidpointLine(x_start, y_start, x_end, y_end);  // Draw the line using Midpoint Algorithm
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0);  // White background
    glPointSize(5.0);  // Larger size of points to make them more visible
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 20, 0, 20);  // Set the coordinate system for smaller values
}

int main(int argc, char** argv) {
    // Input points from user
    cout << "Enter coordinates of first point (x_start y_start): ";
    cin >> x_start >> y_start;
    cout << "Enter coordinates of second point (x_end y_end): ";
    cin >> x_end >> y_end;

    // Initialize GLUT and create window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);  // Window size
    glutInitWindowPosition(100, 100);  // Window position
    glutCreateWindow("Midpoint Line Drawing with Grid");  // Window title

    init();  // Initialize OpenGL state
    glutDisplayFunc(display);  // Set the display callback function
    glutMainLoop();  // Enter the event-processing loop

    return 0;
}
