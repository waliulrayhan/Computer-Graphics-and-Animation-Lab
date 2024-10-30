#include<windows.h>
#include<GL/glut.h>
#include <GL/glu.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>

int angle = 0;

void idle()
{
    angle += 0;
    glutPostRedisplay();
}

/** Utility function to draw filled rectangle with optional border */
void drawRectangle(GLint x1, GLint y1, GLint x2, GLint y2, GLfloat r, GLfloat g, GLfloat b, bool drawBorder = true)
{
    glColor3f(r, g, b);  // Set fill color
    glBegin(GL_POLYGON);
    glVertex2i(x1, y1);
    glVertex2i(x2, y1);
    glVertex2i(x2, y2);
    glVertex2i(x1, y2);
    glEnd();

    /*if (drawBorder)
    {
        glColor3f(0.0, 0.0, 0.0);  // Black border
        glBegin(GL_LINE_LOOP);
        glVertex2i(x1, y1);
        glVertex2i(x2, y1);
        glVertex2i(x2, y2);
        glVertex2i(x1, y2);
        glEnd();
    }*/
}

// Function to draw a circle
void drawCircle(float x, float y, float radius, int num_segments, float r, float g, float b)
{
    glColor3f(r, g, b); // Set color
    glBegin(GL_POLYGON); // Circle as polygon
    //glBegin(GL_LINE_LOOP);
    for (int i = 0; i < num_segments; i++)
    {
        float angle = 2.0f * M_PI * i / num_segments; // Calculate angle
        float dx = radius * cos(angle); // X component
        float dy = radius * sin(angle); // Y component
        glVertex2f(x + dx, y + dy); // Vertex on the circle
    }
    glEnd();


}

/** Display Function */
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);  // Clear the color buffer (with white background)

    /** Draw the red circle (filled) with a black border using gluDisk */

    drawCircle(0,0,130,50,1.0, 0.0, 0.0);

    /** Drawing only borders of all shapes using GL_LINE_LOOP */

    // RIGHT COLUMN - Two vertical rectangles and one horizontal rectangle on top
    drawRectangle(150, 0, 170, -350, 1.0, 1.0, 1.0);  // First vertical rectangle (right side)
    drawRectangle(183, 0, 185, -350, 0.0, 0.0, 0.0);
    drawRectangle(195, 0, 197, -350, 0.0, 0.0, 0.0);
    drawRectangle(208, 0, 210, -350, 0.0, 0.0, 0.0);
    drawRectangle(220, 0, 240, -350, 1.0, 1.0, 1.0);  // Second vertical rectangle (right side)
    drawRectangle(150, 0, 240, 20, 1.0, 1.0, 1.0);    // Horizontal rectangle on top

    drawRectangle(300, -70, 320, -350, 1.0, 1.0, 1.0); // Third vertical rectangle (right side)
    drawRectangle(333, -70, 335, -350, 0.0, 0.0, 0.0);
    drawRectangle(345, -70, 347, -350, 0.0, 0.0, 0.0);
    drawRectangle(358, -70, 360, -350, 0.0, 0.0, 0.0);
    drawRectangle(370, -70, 390, -350, 1.0, 1.0, 1.0); // Fourth vertical rectangle (right side)
    drawRectangle(300, -70, 390, -50, 1.0, 1.0, 1.0);  // Horizontal rectangle on top

    // LEFT COLUMN - Two vertical rectangles and one horizontal rectangle on top
    drawRectangle(-150, 0, -170, -350, 1.0, 1.0, 1.0); // First vertical rectangle (left side)
    drawRectangle(-183, 0, -185, -350, 0.0, 0.0, 0.0);
    drawRectangle(-195, 0, -197, -350, 0.0, 0.0, 0.0);
    drawRectangle(-208, 0, -210, -350, 0.0, 0.0, 0.0);
    drawRectangle(-220, 0, -240, -350, 1.0, 1.0, 1.0); // Second vertical rectangle (left side)
    drawRectangle(-150, 0, -240, 20, 1.0, 1.0, 1.0);   // Horizontal rectangle on top

    drawRectangle(-300, -70, -320, -350, 1.0, 1.0, 1.0); // Third vertical rectangle (left side)
    drawRectangle(-333, -70, -335, -350, 0.0, 0.0, 0.0);
    drawRectangle(-345, -70, -347, -350, 0.0, 0.0, 0.0);
    drawRectangle(-358, -70, -360, -350, 0.0, 0.0, 0.0);
    drawRectangle(-370, -70, -390, -350, 1.0, 1.0, 1.0); // Fourth vertical rectangle (left side)
    drawRectangle(-300, -70, -390, -50, 1.0, 1.0, 1.0);  // Horizontal rectangle on top

    // MID LEFT COLUMN BORDER
    drawRectangle(-80, 50, -60, -350, 1.0, 1.0, 1.0);

    drawRectangle(-47, 50, -45, -350, 0.0, 0.0, 0.0);
    drawRectangle(-31, 50, -29, -350, 0.0, 0.0, 0.0);
    drawRectangle(-14, 50, -12, -350, 0.0, 0.0, 0.0);

    // MID MID COLUMN BORDER
    drawRectangle(0, 250, 20, -350, 1.0, 1.0, 1.0);

    drawRectangle(31, 50, 33, -350, 0.0, 0.0, 0.0);
    drawRectangle(44, 50, 46, -350, 0.0, 0.0, 0.0);
    drawRectangle(58, 50, 60, -350, 0.0, 0.0, 0.0);

    // MID RIGHT COLUMN BORDER
    drawRectangle(70, 50, 90, -350, 1.0, 1.0, 1.0);

    /** ANGLE LEFT COLUMN BORDER - Explicitly defined as per original code */
    glColor3f(1.0, 1.0, 1.0);  // White fill
    glBegin(GL_POLYGON);
    //glColor3f(0.0, 0.0, 0.0);  // Black border
    //glBegin(GL_LINE_LOOP);
    glVertex2i(-100, 250);
    glVertex2i(-80, 250);
    glVertex2i(-60, 50);
    glVertex2i(-80, 50);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);  // Black fill
    glBegin(GL_POLYGON);
    //glColor3f(0.0, 0.0, 0.0);  // Black border
    //glBegin(GL_LINE_LOOP);
    glVertex2i(-47, 50);
    glVertex2i(-45, 50);
    glVertex2i(-64, 235);
    glVertex2i(-66, 235);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);  // Black fill
    glBegin(GL_POLYGON);
    //glColor3f(0.0, 0.0, 0.0);  // Black border
    //glBegin(GL_LINE_LOOP);
    glVertex2i(-31, 50);
    glVertex2i(-29, 50);
    glVertex2i(-42, 235);
    glVertex2i(-44, 235);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);  // Black fill
    glBegin(GL_POLYGON);
    //glColor3f(0.0, 0.0, 0.0);  // Black border
    //glBegin(GL_LINE_LOOP);
    glVertex2i(-14, 50);
    glVertex2i(-12, 50);
    glVertex2i(-20, 235);
    glVertex2i(-22, 235);
    glEnd();

    /** ANGLE RIGHT RIGHT COLUMN BORDER - Explicitly defined as per original code */
    glColor3f(1.0, 1.0, 1.0);  // White fill
    glBegin(GL_POLYGON);
    //glColor3f(0.0, 0.0, 0.0);  // Black border
    //glBegin(GL_LINE_LOOP);
    glVertex2i(100, 250);
    glVertex2i(120, 250);
    glVertex2i(90, 50);
    glVertex2i(70, 50);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);  // Black fill
    glBegin(GL_POLYGON);
    //glColor3f(0.0, 0.0, 0.0);  // Black border
    //glBegin(GL_LINE_LOOP);
    glVertex2i(31, 50);
    glVertex2i(33, 50);
    glVertex2i(40, 235);
    glVertex2i(38, 235);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);  // Black fill
    glBegin(GL_POLYGON);
    //glColor3f(0.0, 0.0, 0.0);  // Black border
    //glBegin(GL_LINE_LOOP);
    glVertex2i(44, 50);
    glVertex2i(46, 50);
    glVertex2i(62, 235);
    glVertex2i(60, 235);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);  // Black fill
    glBegin(GL_POLYGON);
    //glColor3f(0.0, 0.0, 0.0);  // Black border
    //glBegin(GL_LINE_LOOP);
    glVertex2i(58, 50);
    glVertex2i(60, 50);
    glVertex2i(82, 235);
    glVertex2i(80, 235);
    glEnd();

    // TOP BAR BORDER
    drawRectangle(-80, 250, 101, 230, 1.0, 1.0, 1.0);

    /** Horizontal Line Under Shaheed Minar */
    glColor3f(0.0, 0.0, 0.0);  // Set the color to white for the line
    glBegin(GL_LINES);
    glVertex2i(-450, -350);  // Left point of the horizontal line
    glVertex2i(450, -350);   // Right point of the horizontal line
    glEnd();

    glColor3f(0.192, 0.318, 0.118);  // Black fill
    glBegin(GL_POLYGON);
    //glColor3f(0.0, 0.0, 0.0);  // Black border
    //glBegin(GL_LINE_LOOP);
    glVertex2i(-450, -550);
    glVertex2i(450, -550);
    glVertex2i(450, -350);
    glVertex2i(-450, -350);
    glEnd();

    glFlush();
}

void init(void)
{
    glClearColor(0.192, 0.318, 0.118, 1.0);  // Set background color
    glClearColor(0.0, 0.7, 1.0, 1.0);
    //glClearColor(1.0, 1.0, 1.0, 1.0);  // Set background color
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
