#include <windows.h>
#include <GL/glut.h>

// Display callback function
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Reset color to black for the polygons' borders
    glColor3f(0.0, 0.0, 0.0);

    glBegin(GL_POLYGON); // fill color
    //glBegin(GL_LINE_LOOP); // outline color
    // glColor3f(1.0, 1.0, 0.0);
    glColor3f(0.55, 0.27, 0.07);
    glVertex2i(200, 300);
    glVertex2i(350, 300);
    glVertex2i(420, 350);
    glVertex2i(270, 350);
    glEnd();

    //glBegin(GL_POLYGON);
    glBegin(GL_LINE_LOOP);
    glVertex2i(200, 280);
    glVertex2i(350, 280);
    glVertex2i(350, 300);
    glVertex2i(200, 300);
    glEnd();

    //glBegin(GL_POLYGON);
    glBegin(GL_LINE_LOOP);
    glVertex2i(350, 280);
    glVertex2i(420, 330);
    glVertex2i(420, 350);
    glVertex2i(350, 300);
    glEnd();

    //glBegin(GL_POLYGON);
    glBegin(GL_LINE_LOOP);
    glVertex2i(200, 280);
    glVertex2i(200, 180);
    glVertex2i(220, 180);
    glVertex2i(220, 280);
    glEnd();

    //glBegin(GL_POLYGON);
    glBegin(GL_LINE_LOOP);
    glVertex2i(330, 280);
    glVertex2i(330, 180);
    glVertex2i(350, 180);
    glVertex2i(350, 280);
    glEnd();

    //glBegin(GL_POLYGON);
    glBegin(GL_LINE_LOOP);
    glVertex2i(270, 280);
    glVertex2i(270, 230);
    glVertex2i(290, 230);
    glVertex2i(290, 280);
    glEnd();

    //glBegin(GL_POLYGON);
    glBegin(GL_LINE_LOOP);
    glVertex2i(420, 330);
    glVertex2i(420, 230);
    glVertex2i(400, 230);
    glVertex2i(400, 315);
    glEnd();

    /* Remove for table */

    /*
    //glBegin(GL_POLYGON);
    glBegin(GL_LINE_LOOP);
    glVertex2i(270, 350);
    glVertex2i(420, 350);
    glVertex2i(420, 500);
    glVertex2i(270, 500);
    glEnd();

    //glBegin(GL_POLYGON);
    glBegin(GL_LINE_LOOP);
    glVertex2i(290, 350);
    glVertex2i(400, 350);
    glVertex2i(400, 480);
    glVertex2i(290, 480);
    glEnd();

    //glBegin(GL_POLYGON);
    glBegin(GL_LINE_LOOP);
    glVertex2i(320, 480);
    glVertex2i(320, 350);
    glVertex2i(330, 350);
    glVertex2i(330, 480);
    glEnd();

    //glBegin(GL_POLYGON);
    glBegin(GL_LINE_LOOP);
    glVertex2i(360, 350);
    glVertex2i(370, 350);
    glVertex2i(370, 480);
    glVertex2i(360, 480);
    glEnd();
    */

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
