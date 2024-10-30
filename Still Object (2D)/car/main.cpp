#include <windows.h>
#include <GL/glut.h>
#include <math.h>

void drawCircle(float centerX, float centerY, float radius, int numSegments, float r, float g, float b) {
    // Set the fill color using the provided RGB values
    glColor3f(r, g, b);
    //glBegin(GL_LINE_LOOP);

    // Start drawing the filled circle
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(centerX, centerY); // Center of the circle
    for (int i = 0; i <= numSegments; i++) { // <= to complete the loop
        float theta = 2.0f * 3.1415926f * float(i) / float(numSegments); // Angle
        float x = radius * cosf(theta); // X coordinate
        float y = radius * sinf(theta); // Y coordinate
        glVertex2f(centerX + x, centerY + y);
    }
    glEnd();
}


// Display callback function
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Reset color to black for the polygons' borders
    glColor3f(0.0, 0.0, 0.0);

    glBegin(GL_POLYGON);
    //glBegin(GL_LINE_LOOP);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2i(150, 200);
    glVertex2i(300, 200);
    glVertex2i(300, 300);
    glVertex2i(150, 300);
    glEnd();

    // glColor3f(0.0, 0.0, 0.0); // reset color

    //glBegin(GL_POLYGON);
    glBegin(GL_LINE_LOOP);
    glVertex2i(300, 200);
    glVertex2i(450, 200);
    glVertex2i(450, 300);
    glVertex2i(300, 300);
    glEnd();

    //glBegin(GL_POLYGON);
    glBegin(GL_LINE_LOOP);
    glVertex2i(170, 300);
    glVertex2i(235, 300);
    glVertex2i(235, 400);
    glVertex2i(203, 400);
    glEnd();

    //glBegin(GL_POLYGON);
    glBegin(GL_LINE_LOOP);
    glVertex2i(235, 300);
    glVertex2i(375, 300);
    glVertex2i(375, 400);
    glVertex2i(235, 400);
    glEnd();

    //glBegin(GL_POLYGON);
    glBegin(GL_LINE_LOOP);
    glVertex2i(375, 300);
    glVertex2i(430, 300);
    glVertex2i(404, 400);
    glVertex2i(375, 400);
    glEnd();

    drawCircle(225, 180, 40, 50, 0.0, 0.0, 0.0);
    drawCircle(225, 180, 15, 50, 1.0, 1.0, 1.0);

    drawCircle(375, 180, 40, 50, 0.0, 0.0, 0.0);
    drawCircle(375, 180, 15, 50, 1.0, 1.0, 1.0);

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
