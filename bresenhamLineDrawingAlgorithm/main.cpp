#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include <cmath>

using namespace std;

int x_start, y_start, x_end, y_end;  // Store coordinates for the line

void drawGrid() {
    glColor3f(0.0, 0.0, 0.0);  // Set grid color to black
    glBegin(GL_LINES);

    // Draw vertical grid lines
    for (int i = -20; i <= 20; i++) {
        glVertex2f(i, -20);  // Vertical line
        glVertex2f(i, 20);
    }

    // Draw horizontal grid lines
    for (int i = -20; i <= 20; i++) {
        glVertex2f(-20, i);  // Horizontal line
        glVertex2f(20, i);
    }

    glEnd();
}

void BresenhamLine(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int p = 2 * dy - dx;  // Decision parameter
    int twoDy = 2 * dy;
    int twoDyMinusDx = 2 * (dy - dx);

    int x, y;
    if (x1 > x2) {
        x = x2;
        y = y2;
        x2 = x1;
    } else {
        x = x1;
        y = y1;
    }

    // Set point color to red
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POINTS);

    // Plot the first point
    glVertex2i(x, y);
    cout << "(" << x << ", " << y << ")" << endl;

    // Loop through to calculate and plot the points using Bresenham's algorithm
    while (x < x2) {
        x++;
        if (p < 0) {
            p += twoDy;
        } else {
            y++;
            p += twoDyMinusDx;
        }

        glVertex2i(x, y);  // Plot the points on OpenGL window
        cout << "(" << x << ", " << y << ")" << endl;  // Print the points to the console
    }

    glEnd();
    glFlush();  // Flush the drawing to the window
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);  // Clear display window
    drawGrid();  // Draw the grid
    BresenhamLine(x_start, y_start, x_end, y_end);  // Draw the line using Bresenham's algorithm
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0);  // White background
    glPointSize(5.0);  // Larger size of points to make them more visible
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 20, 0, 20);  // Set the coordinate system for small values
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
    glutCreateWindow("Bresenham Line Drawing Algorithm with Grid");  // Window title

    init();  // Initialize OpenGL state
    glutDisplayFunc(display);  // Set the display callback function
    glutMainLoop();  // Enter the event-processing loop

    return 0;
}
