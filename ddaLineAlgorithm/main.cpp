#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include <cmath>

using namespace std;

int x_start, y_start, x_end, y_end;  // Renamed variables to avoid conflict
float dx, dy, steps;
float xIncrement, yIncrement;
float x, y;  // Track current position of drawing

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

void DDA(int x_start, int y_start, int x_end, int y_end) {
    dx = x_end - x_start;
    dy = y_end - y_start;
    steps = max(abs(dx), abs(dy));
    xIncrement = dx / (float)steps;
    yIncrement = dy / (float)steps;

    x = x_start;
    y = y_start;

    // Print the initial and final points in the console
    cout << "(" << x_start << ", " << y_start << ") -> (" << x_end << ", " << y_end << ")" << endl;
    cout << "Points on the line:" << endl;

    glColor3f(1.0, 0.0, 0.0);  // Set color for the points (red)
    glBegin(GL_POINTS);

    // Plot the points and print them to the console
    for (int i = 0; i <= steps; i++) {
        glVertex2i(round(x), round(y));  // Plot points in OpenGL
        cout << "(" << round(x) << ", " << round(y) << ")" << endl;  // Print points to the console
        x += xIncrement;
        y += yIncrement;
    }

    glEnd();
    glFlush();  // Flush the drawing to the window
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);  // Clear display window
    drawGrid();  // Call function to draw the grid
    DDA(x_start, y_start, x_end, y_end);  // Call the DDA algorithm to draw the line
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0);  // White background
    glPointSize(5.0);  // Larger size of points to make them more visible
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 20, 0, 20);  // Adjusted window to fit smaller coordinates
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
    glutCreateWindow("DDA Line Drawing with Grid");  // Window title

    init();  // Initialize OpenGL state
    glutDisplayFunc(display);  // Set the display callback function
    glutMainLoop();  // Enter the event-processing loop

    return 0;
}
