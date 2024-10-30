#include<windows.h>
#include<GL/glut.h>
#include <GL/glu.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>

int angle  =  0;

void idle()
{
    angle += 0;
    glutPostRedisplay();
}

/** Display Function */
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);  // Clear the color buffer (with white background)

    /** Draw the red circle (filled) with a black border using gluDisk */

    // Create a quadric object for drawing the circle
    GLUquadric* quadric = gluNewQuadric();

    // Draw filled red circle
    glColor3f(1.0, 0.0, 0.0);  // Set fill color to red
    gluDisk(quadric, 0, 120, 100, 1);  // Draw filled circle (radius 120)

    // Draw the black border for the circle
    //glColor3f(0.0, 0.0, 0.0);  // Set border color to black
    gluQuadricDrawStyle(quadric, GLU_LINE);  // Set to draw border (outline)
    gluDisk(quadric, 0, 120, 100, 1);  // Draw circle outline

    gluDeleteQuadric(quadric);  // Clean up the quadric object

    /** Drawing only borders of all shapes using GL_LINE_LOOP */

    // RIGHT COLUMN - Two vertical rectangles and one horizontal rectangle on top
    // First vertical rectangle (right side)
    glColor3f(1.0, 1.0, 1.0);  // White fill
    glBegin(GL_POLYGON);
    glVertex2i(150, 0);  // Bottom-left
    glVertex2i(170, 0);  // Bottom-right
    glVertex2i(170, -350);  // Top-right
    glVertex2i(150, -350);  // Top-left
    glEnd();
    //glColor3f(0.0, 0.0, 0.0);  // Black border
    glBegin(GL_LINE_LOOP);
    glVertex2i(150, 0);  // Bottom-left
    glVertex2i(170, 0);  // Bottom-right
    glVertex2i(170, -350);  // Top-right
    glVertex2i(150, -350);  // Top-left
    glEnd();

    // Second vertical rectangle (right side)
    glColor3f(1.0, 1.0, 1.0);  // White fill
    glBegin(GL_POLYGON);
    glVertex2i(220, 0);  // Bottom-left
    glVertex2i(240, 0);  // Bottom-right
    glVertex2i(240, -350);  // Top-right
    glVertex2i(220, -350);  // Top-left
    glEnd();
    //glColor3f(0.0, 0.0, 0.0);  // Black border
    glBegin(GL_LINE_LOOP);
    glVertex2i(220, 0);  // Bottom-left
    glVertex2i(240, 0);  // Bottom-right
    glVertex2i(240, -350);  // Top-right
    glVertex2i(220, -350);  // Top-left
    glEnd();

    // Horizontal rectangle on top
    glColor3f(1.0, 1.0, 1.0);  // White fill
    glBegin(GL_POLYGON);
    glVertex2i(150, 0);  // Bottom-left
    glVertex2i(240, 0);  // Bottom-right
    glVertex2i(240, 20);  // Top-right
    glVertex2i(150, 20);  // Top-left
    glEnd();
    //glColor3f(0.0, 0.0, 0.0);  // Black border
    glBegin(GL_LINE_LOOP);
    glVertex2i(150, 0);  // Bottom-left
    glVertex2i(240, 0);  // Bottom-right
    glVertex2i(240, 20);  // Top-right
    glVertex2i(150, 20);  // Top-left
    glEnd();

    // Third vertical rectangle (right side)
    glColor3f(1.0, 1.0, 1.0);  // White fill
    glBegin(GL_POLYGON);
    glVertex2i(300, -70);  // Bottom-left
    glVertex2i(320, -70);  // Bottom-right
    glVertex2i(320, -350);  // Top-right
    glVertex2i(300, -350);  // Top-left
    glEnd();
    //glColor3f(0.0, 0.0, 0.0);  // Black border
    glBegin(GL_LINE_LOOP);
    glVertex2i(300, -70);  // Bottom-left
    glVertex2i(320, -70);  // Bottom-right
    glVertex2i(320, -350);  // Top-right
    glVertex2i(300, -350);  // Top-left
    glEnd();

    // Fourth vertical rectangle (right side)
    glColor3f(1.0, 1.0, 1.0);  // White fill
    glBegin(GL_POLYGON);
    glVertex2i(370, -70);  // Bottom-left
    glVertex2i(390, -70);  // Bottom-right
    glVertex2i(390, -350);  // Top-right
    glVertex2i(370, -350);  // Top-left
    glEnd();
    //glColor3f(0.0, 0.0, 0.0);  // Black border
    glBegin(GL_LINE_LOOP);
    glVertex2i(370, -70);  // Bottom-left
    glVertex2i(390, -70);  // Bottom-right
    glVertex2i(390, -350);  // Top-right
    glVertex2i(370, -350);  // Top-left
    glEnd();

    // Horizontal rectangle on top
    glColor3f(1.0, 1.0, 1.0);  // White fill
    glBegin(GL_POLYGON);
    glVertex2i(300, -70);  // Bottom-left
    glVertex2i(390, -70);  // Bottom-right
    glVertex2i(390, -50);  // Top-right
    glVertex2i(300, -50);  // Top-left
    glEnd();
    //glColor3f(0.0, 0.0, 0.0);  // Black border
    glBegin(GL_LINE_LOOP);
    glVertex2i(300, -70);  // Bottom-left
    glVertex2i(390, -70);  // Bottom-right
    glVertex2i(390, -50);  // Top-right
    glVertex2i(300, -50);  // Top-left
    glEnd();

    // LEFT COLUMN - Two vertical rectangles and one horizontal rectangle on top
    // First vertical rectangle (left side)
    glColor3f(1.0, 1.0, 1.0);  // White fill
    glBegin(GL_POLYGON);
    glVertex2i(-150, 0);  // Bottom-left
    glVertex2i(-170, 0);  // Bottom-right
    glVertex2i(-170, -350);  // Top-right
    glVertex2i(-150, -350);  // Top-left
    glEnd();
    //glColor3f(0.0, 0.0, 0.0);  // Black border
    glBegin(GL_LINE_LOOP);
    glVertex2i(-150, 0);  // Bottom-left
    glVertex2i(-170, 0);  // Bottom-right
    glVertex2i(-170, -350);  // Top-right
    glVertex2i(-150, -350);  // Top-left
    glEnd();

    // Second vertical rectangle (left side)
    glColor3f(1.0, 1.0, 1.0);  // White fill
    glBegin(GL_POLYGON);
    glVertex2i(-220, 0);  // Bottom-left
    glVertex2i(-240, 0);  // Bottom-right
    glVertex2i(-240, -350);  // Top-right
    glVertex2i(-220, -350);  // Top-left
    glEnd();
    //glColor3f(0.0, 0.0, 0.0);  // Black border
    glBegin(GL_LINE_LOOP);
    glVertex2i(-220, 0);  // Bottom-left
    glVertex2i(-240, 0);  // Bottom-right
    glVertex2i(-240, -350);  // Top-right
    glVertex2i(-220, -350);  // Top-left
    glEnd();

    // Horizontal rectangle on top
    glColor3f(1.0, 1.0, 1.0);  // White fill
    glBegin(GL_POLYGON);
    glVertex2i(-150, 0);  // Bottom-left
    glVertex2i(-240, 0);  // Bottom-right
    glVertex2i(-240, 20);  // Top-right
    glVertex2i(-150, 20);  // Top-left
    glEnd();
    //glColor3f(0.0, 0.0, 0.0);  // Black border
    glBegin(GL_LINE_LOOP);
    glVertex2i(-150, 0);  // Bottom-left
    glVertex2i(-240, 0);  // Bottom-right
    glVertex2i(-240, 20);  // Top-right
    glVertex2i(-150, 20);  // Top-left
    glEnd();

    // Third vertical rectangle (left side)
    glColor3f(1.0, 1.0, 1.0);  // White fill
    glBegin(GL_POLYGON);
    glVertex2i(-300, -70);  // Bottom-left
    glVertex2i(-320, -70);  // Bottom-right
    glVertex2i(-320, -350);  // Top-right
    glVertex2i(-300, -350);  // Top-left
    glEnd();
    //glColor3f(0.0, 0.0, 0.0);  // Black border
    glBegin(GL_LINE_LOOP);
    glVertex2i(-300, -70);  // Bottom-left
    glVertex2i(-320, -70);  // Bottom-right
    glVertex2i(-320, -350);  // Top-right
    glVertex2i(-300, -350);  // Top-left
    glEnd();

    // Fourth vertical rectangle (left side)
    glColor3f(1.0, 1.0, 1.0);  // White fill
    glBegin(GL_POLYGON);
    glVertex2i(-370, -70);  // Bottom-left
    glVertex2i(-390, -70);  // Bottom-right
    glVertex2i(-390, -350);  // Top-right
    glVertex2i(-370, -350);  // Top-left
    glEnd();
    //glColor3f(0.0, 0.0, 0.0);  // Black border
    glBegin(GL_LINE_LOOP);
    glVertex2i(-370, -70);  // Bottom-left
    glVertex2i(-390, -70);  // Bottom-right
    glVertex2i(-390, -350);  // Top-right
    glVertex2i(-370, -350);  // Top-left
    glEnd();

    // Horizontal rectangle on top
    glColor3f(1.0, 1.0, 1.0);  // White fill
    glBegin(GL_POLYGON);
    glVertex2i(-300, -70);  // Bottom-left
    glVertex2i(-390, -70);  // Bottom-right
    glVertex2i(-390, -50);  // Top-right
    glVertex2i(-300, -50);  // Top-left
    glEnd();
    //glColor3f(0.0, 0.0, 0.0);  // Black border
    glBegin(GL_LINE_LOOP);
    glVertex2i(-300, -70);  // Bottom-left
    glVertex2i(-390, -70);  // Bottom-right
    glVertex2i(-390, -50);  // Top-right
    glVertex2i(-300, -50);  // Top-left
    glEnd();

    // MID LEFT COLUMN BORDER
    glColor3f(1.0, 1.0, 1.0);  // White fill
    glBegin(GL_POLYGON);
    glVertex2i(-80, 50);
    glVertex2i(-60, 50);
    glVertex2i(-60, -350);
    glVertex2i(-80, -350);
    glEnd();
    //glColor3f(0.0, 0.0, 0.0);  // Black border
    glBegin(GL_LINE_LOOP);
    glVertex2i(-80, 50);
    glVertex2i(-60, 50);
    glVertex2i(-60, -350);
    glVertex2i(-80, -350);
    glEnd();

    // MID MID COLUMN BORDER
    glColor3f(1.0, 1.0, 1.0);  // White fill
    glBegin(GL_POLYGON);
    glVertex2i(0, 250);
    glVertex2i(20, 250);
    glVertex2i(20, -350);
    glVertex2i(0, -350);
    glEnd();
    //glColor3f(0.0, 0.0, 0.0);  // Black border
    glBegin(GL_LINE_LOOP);
    glVertex2i(0, 250);
    glVertex2i(20, 250);
    glVertex2i(20, -350);
    glVertex2i(0, -350);
    glEnd();

    // MID RIGHT COLUMN BORDER
    glColor3f(1.0, 1.0, 1.0);  // White fill
    glBegin(GL_POLYGON);
    glVertex2i(90, 50);
    glVertex2i(70, 50);
    glVertex2i(70, -350);
    glVertex2i(90, -350);
    glEnd();
    //glColor3f(0.0, 0.0, 0.0);  // Black border
    glBegin(GL_LINE_LOOP);
    glVertex2i(90, 50);
    glVertex2i(70, 50);
    glVertex2i(70, -350);
    glVertex2i(90, -350);
    glEnd();

    // ANGLE LEFT COLUMN BORDER
    glColor3f(1.0, 1.0, 1.0);  // White fill
    glBegin(GL_POLYGON);
    glVertex2i(-100, 250);
    glVertex2i(-80, 250);
    glVertex2i(-60, 50);
    glVertex2i(-80, 50);
    glEnd();
    //glColor3f(0.0, 0.0, 0.0);  // Black border
    glBegin(GL_LINE_LOOP);
    glVertex2i(-100, 250);
    glVertex2i(-80, 250);
    glVertex2i(-60, 50);
    glVertex2i(-80, 50);
    glEnd();

    // ANGLE RIGHT RIGHT COLUMN BORDER
    glColor3f(1.0, 1.0, 1.0);  // White fill
    glBegin(GL_POLYGON);
    glVertex2i(100, 250);
    glVertex2i(120, 250);
    glVertex2i(90, 50);
    glVertex2i(70, 50);
    glEnd();
    //glColor3f(0.0, 0.0, 0.0);  // Black border
    glBegin(GL_LINE_LOOP);
    glVertex2i(100, 250);
    glVertex2i(120, 250);
    glVertex2i(90, 50);
    glVertex2i(70, 50);
    glEnd();

    // TOP BAR BORDER
    glColor3f(1.0, 1.0, 1.0);  // White fill
    glBegin(GL_POLYGON);
    glVertex2i(-100, 250);
    glVertex2i(101, 250);
    glVertex2i(97, 230);
    glVertex2i(-96, 230);
    glEnd();
    //glColor3f(0.0, 0.0, 0.0);  // Black border
    glBegin(GL_LINE_LOOP);
    glVertex2i(-100, 250);
    glVertex2i(101, 250);
    glVertex2i(97, 230);
    glVertex2i(-96, 230);
    glEnd();

    /** Horizontal Line Under Shaheed Minar */
    glColor3f(1.0, 1.0, 1.0);  // Set the color to white for the line
    glBegin(GL_LINES);
    glVertex2i(-450, -350);  // Left point of the horizontal line
    glVertex2i(450, -350);   // Right point of the horizontal line
    glEnd();

    glFlush();
}

void init(void)
{
    glClearColor(0.192, 0.318, 0.118, 1.0);  // Set background color
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-450, 450, -550, 450);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(700, 700);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Shaheed Minar");
    init();
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutMainLoop();

    return 0;
}
