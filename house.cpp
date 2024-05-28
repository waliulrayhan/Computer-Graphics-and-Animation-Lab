#include <windows.h>

#include <GL/glut.h>

// Initialize OpenGL Graphics
void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 640.0);
}

// Display callback function
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the house body
    glBegin(GL_POLYGON);
    glColor3f(0.7, 0.5, 0.3);
    glVertex2i(200, 200);
    glVertex2i(400, 200);
    glVertex2i(400, 400);
    glVertex2i(200, 400);
    glEnd();

    // Draw the roof
    glBegin(GL_TRIANGLES);
    glColor3f(0.5, 0.0, 0.0);
    glVertex2i(180, 400);
    glVertex2i(420, 400);
    glVertex2i(300, 500);
    glEnd();

    // Draw the door
    glBegin(GL_POLYGON);
    glColor3f(0.4, 0.2, 0.1);
    glVertex2i(270, 200);
    glVertex2i(330, 200);
    glVertex2i(330, 300);
    glVertex2i(270, 300);
    glEnd();

    // Draw windows
    glColor3f(0.0, 0.0, 1.0);
    // Left window
    glBegin(GL_POLYGON);
    glVertex2i(220, 320);
    glVertex2i(260, 320);
    glVertex2i(260, 360);
    glVertex2i(220, 360);
    glEnd();
    // Right window
    glBegin(GL_POLYGON);
    glVertex2i(340, 320);
    glVertex2i(380, 320);
    glVertex2i(380, 360);
    glVertex2i(340, 360);
    glEnd();

    glFlush();
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Nishat's House");
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(50, 50);
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;
}
