#include <windows.h>
#include <GL/glut.h>

// Display callback function
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the house body
    glBegin(GL_POLYGON);
    //glColor3f(0.7, 0.5, 0.3);
    glBegin(GL_LINE_LOOP);
    glVertex2i(400, 200);
    glVertex2i(200, 200);
    glVertex2i(200, 400);
    glVertex2i(400, 400);
    glEnd();

    // Draw the roof
    glBegin(GL_TRIANGLES);
    //glColor3f(0.5, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(180, 400);
    glVertex2i(420, 400);
    glVertex2i(300, 500);
    glEnd();

    glFlush();
}

// Initialize OpenGL Graphics
void init()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 640.0);
}

// Main function
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutCreateWindow("Basics");
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(50, 50);
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;
}
