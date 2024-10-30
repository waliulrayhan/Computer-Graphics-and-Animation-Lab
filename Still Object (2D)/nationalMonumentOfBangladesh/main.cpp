#include <windows.h>
#include <GL/glut.h>
#include <cmath>

// Function to draw a circle border (used for the flag's red circle)
void drawCircleBorder(float cx, float cy, float radius, int segments)
{
    glBegin(GL_LINE_LOOP);  // Use GL_LINE_LOOP for a circle border
    for (int i = 0; i < segments; i++)
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(segments);
        float x = radius * cosf(theta); // x coordinate
        float y = radius * sinf(theta); // y coordinate
        glVertex2f(x + cx, y + cy);     // Output vertex
    }
    glEnd();
}

// Function to draw a filled circle
void drawFilledCircle(float cx, float cy, float radius, int segments)
{
    glBegin(GL_TRIANGLE_FAN);  // Use GL_TRIANGLE_FAN for the filled circle
    glVertex2f(cx, cy);  // Center point of the circle
    for (int i = 0; i <= segments; i++)
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(segments);
        float x = radius * cosf(theta); // x coordinate
        float y = radius * sinf(theta); // y coordinate
        glVertex2f(x + cx, y + cy);     // Output vertex
    }
    glEnd();
}

// Display callback function
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);      // Clear the color buffer

    int base_left_x = 160;  // Initial left point of the base
    int base_right_x = 480; // Initial right point of the base
    int base_y = 100;       // Y-coordinate of the base (same for all triangles)

    int height_increase = 50;  // Initial height increment
    int base_shrink = 20;      // How much to decrease the base width for each triangle

float colors[7][3] =
{
    {0.05, 0.05, 0.05},  // Very Dark Gray (almost black)
    {0.2, 0.2, 0.2},     // Dark Gray
    {0.35, 0.35, 0.35},  // Medium Dark Gray
    {0.5, 0.5, 0.5},     // Mid Gray
    {0.65, 0.65, 0.65},  // Medium Light Gray
    {0.75, 0.75, 0.75},  // Light Gray
    {0.85, 0.85, 0.85}   // Very Light Gray (but not white)
};

    // Draw the 7 triangles with both fill and borders
    for (int i = 0; i < 7; i++)
    {
        /* ------ Draw the filled triangle with color ------ */
        glColor3f(colors[i][0], colors[i][1], colors[i][2]);
        glBegin(GL_TRIANGLES);
        //glColor3f(0.0, 0.0, 0.0);  // Set color to black for the borders
        //glBegin(GL_LINE_LOOP);  // Use GL_LINE_LOOP for borders
        glVertex2i(base_left_x, base_y);   // Bottom left
        glVertex2i(base_right_x, base_y);  // Bottom right
        glVertex2i((base_left_x + base_right_x) / 2, base_y + height_increase);   // Top middle
        glEnd();

        // Update the base and height for the next triangle
        base_left_x += base_shrink;
        base_right_x -= base_shrink;
        height_increase += 50;  // Increase the height for the next triangle
    }

    glColor3f(0.5, 0.5, 0.5);  // Black fill
    glBegin(GL_POLYGON);
    //glColor3f(0.0, 0.0, 0.0);  // Black border
    //glBegin(GL_LINE_LOOP);
    glVertex2i(305, 253);
    glVertex2i(335, 253);
    glVertex2i(320, 300);
    glEnd();

    glColor3f(0.5, 0.5, 0.5);  // Black fill
    glBegin(GL_POLYGON);
    //glColor3f(0.0, 0.0, 0.0);  // Black border
    //glBegin(GL_LINE_LOOP);
    glVertex2i(320, 200);
    glVertex2i(335, 247);
    glVertex2i(305, 247);
    glEnd();

    glColor3f(0.75, 0.75, 0.75);  // Black fill
    glBegin(GL_POLYGON);
    //glColor3f(0.0, 0.0, 0.0);  // Black border
    //glBegin(GL_LINE_LOOP);
    glVertex2i(305, 247);
    glVertex2i(335, 247);
    glVertex2i(335, 253);
    glVertex2i(305, 253);
    glEnd();

    glColor3f(0.35, 0.35, 0.35);  // Black fill
    glBegin(GL_POLYGON);
    //glColor3f(0.0, 0.0, 0.0);  // Black border
    //glBegin(GL_LINE_LOOP);
    glVertex2i(318, 430);
    glVertex2i(322, 430);
    glVertex2i(320, 450);
    glEnd();

    glColor3f(0.65, 0.65, 0.65);  // Black fill
    glBegin(GL_POLYGON);
    //glColor3f(0.0, 0.0, 0.0);  // Black border
    //glBegin(GL_LINE_LOOP);
    glVertex2i(280, 100);
    glVertex2i(360, 100);
    glVertex2i(320, 120);
    glEnd();

    // ---- Draw the flag on the left side of the monument ----

    /* ------ Draw the filled flag rectangle (green) ------ */
    glColor3f(0.0, 0.6, 0.0);  // Set color to green for the flag
    glBegin(GL_POLYGON);
    //glColor3f(0.0, 0.0, 0.0);  // Set color to black for the flag border
    //glBegin(GL_LINE_LOOP);  // Use GL_LINE_LOOP for the rectangle border
    glVertex2i(100, 300);  // Bottom-left of the flag
    glVertex2i(170, 300);  // Bottom-right of the flag
    glVertex2i(170, 350);  // Top-right of the flag
    glVertex2i(100, 350);  // Top-left of the flag
    glEnd();

    /* ------ Draw the filled red circle in the flag ------ */
    glColor3f(1.0, 0.0, 0.0);  // Set color to red for the circle
    drawFilledCircle(135.0f, 325.0f, 15.0f, 100);  // Center at (135, 325) with radius 15

    // Draw the black border for the red circle
    //glColor3f(0.0, 0.0, 0.0);  // Set color to black for the circle border
    //drawCircleBorder(135.0f, 325.0f, 15.0f, 100);  // Draw the circle border

    // Draw the flagpole (black line)
    glColor3f(0.6, 0.3, 0.1);   // Set color to black for the flagpole
    glBegin(GL_POLYGON);
    //glColor3f(0.0, 0.0, 0.0);  // Black border
    //glBegin(GL_LINE_LOOP);
    glVertex2i(98, 100);// Bottom of the flagpole
    glVertex2i(100, 100);
    glVertex2i(100, 350);// Top of the flagpole
    glVertex2i(98, 350);
    glEnd();

    // ---- Draw the line below the monument ----
    //glColor3f(0.0, 0.0, 0.0);  // Set color to black for the line
    //glBegin(GL_LINES);
    //glVertex2i(50, 100);   // Left end of the line
    //glVertex2i(550, 100);   // Right end of the line
    //glEnd();

    glColor3f(0.192, 0.318, 0.118);  // Black fill
    glBegin(GL_POLYGON);
    //glColor3f(0.0, 0.0, 0.0);  // Black border
    //glBegin(GL_LINE_LOOP);
    glVertex2i(0, 0);
    glVertex2i(640, 0);
    glVertex2i(640, 100);
    glVertex2i(0, 100);
    glEnd();

    glFlush();  // Render now
}

// Initialize OpenGL Graphics
void init()
{
    //glClearColor(1.0, 1.0, 1.0, 1.0);  // Set background color to white
    glClearColor(0.0, 0.7, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);       // Set projection parameters
    glLoadIdentity();                  // Reset transformation
    gluOrtho2D(0.0, 640.0, 0.0, 480.0); // Set the coordinate system
}

// Main function
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutCreateWindow("National Monument of Bangladesh");
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(50, 50);
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;
}
