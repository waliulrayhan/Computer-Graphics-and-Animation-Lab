#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include <cmath>

using namespace std;

int radius;  // Store the radius for the circle

void drawGrid() {
    glColor3f(0.0, 0.0, 0.0);  // Set grid color to black
    glBegin(GL_LINES);

    // Draw vertical grid lines
    for (int i = -radius - 10; i <= radius + 10; i++) {
        glVertex2f(i, -radius - 10);  // Vertical line
        glVertex2f(i, radius + 10);
    }

    // Draw horizontal grid lines
    for (int i = -radius - 10; i <= radius + 10; i++) {
        glVertex2f(-radius - 10, i);  // Horizontal line
        glVertex2f(radius + 10, i);
    }

    glEnd();
}

void plotCirclePoints(int x, int y) {
    glBegin(GL_POINTS);

    // Plot the eight symmetric points
    glVertex2i(x, y);
    glVertex2i(-x, y);
    glVertex2i(x, -y);
    glVertex2i(-x, -y);
    glVertex2i(y, x);
    glVertex2i(-y, x);
    glVertex2i(y, -x);
    glVertex2i(-y, -x);

    glEnd();
}

void MidpointCircle(int radius) {
    int x = 0;
    int y = radius;
    int d = 1 - radius;
    int deltaE = 3;
    int deltaSE = -2 * radius + 5;

    cout << "Midpoint Circle Drawing Algorithm:" << endl;
    cout << "Radius: " << radius << endl;
    cout << "Points on the circle:" << endl;

    // Set point color to red
    glColor3f(1.0, 0.0, 0.0);  // Red color for circle points

    // Draw and print the points
    while (x <= y) {
        // Plot the points on the OpenGL window
        plotCirclePoints(x, y);

        // Print the points to the console
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

void display() {
    glClear(GL_COLOR_BUFFER_BIT);  // Clear display window
    drawGrid();  // Draw the grid
    MidpointCircle(radius);  // Call the Midpoint Circle Algorithm to draw the circle
    glFlush();  // Flush the drawing to the window
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0);  // White background
    glPointSize(5.0);  // Larger size of points to make them more visible
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-radius - 10, radius + 10, -radius - 10, radius + 10);  // Set window coordinates based on the radius
}

int main(int argc, char** argv) {
    // Input radius from the user
    cout << "Enter radius of circle: ";
    cin >> radius;

    // Initialize GLUT and create window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);  // Window size
    glutInitWindowPosition(100, 100);  // Window position
    glutCreateWindow("Midpoint Circle Drawing with Grid");  // Window title

    init();  // Initialize OpenGL state
    glutDisplayFunc(display);  // Set the display callback function
    glutMainLoop();  // Enter the event-processing loop

    return 0;
}
