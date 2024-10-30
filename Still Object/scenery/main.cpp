#include <windows.h>
#include <GL/glut.h>
#include <math.h>

// Function to draw a filled circle
void drawFilledCircle(float cx, float cy, float radius, int num_segments) {
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i <= num_segments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
        float x = radius * cosf(theta);
        float y = radius * sinf(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}

// Function to draw the car
void drawCar() {
    // Car body
    glColor3f(0.8, 0.0, 0.0);  // Red color for the car
    glBegin(GL_POLYGON);
    glVertex2i(100, 50);  // Lowered the car body further
    glVertex2i(200, 50);
    glVertex2i(200, 80);
    glVertex2i(100, 80);
    glEnd();

    // Car roof
    glColor3f(0.6, 0.0, 0.0);  // Darker red for the roof
    glBegin(GL_POLYGON);
    glVertex2i(120, 80);
    glVertex2i(180, 80);
    glVertex2i(170, 100);
    glVertex2i(130, 100);
    glEnd();

    // Car wheels
    glColor3f(0.0, 0.0, 0.0);  // Black wheels
    drawFilledCircle(130, 50, 10, 30);  // Left wheel at y = 50
    drawFilledCircle(170, 50, 10, 30);  // Right wheel at y = 50

    glColor3f(1.0, 1.0, 1.0);  // white wheels point
    drawFilledCircle(130, 50, 3, 30);  // Left wheel at y = 50
    drawFilledCircle(170, 50, 3, 30);  // Right wheel at y = 50

    // Car windows (blue), making the windows closer to the roof
    glColor3f(0.0, 0.7, 1.0);
    glBegin(GL_POLYGON);  // Front window
    glVertex2i(135, 85);
    glVertex2i(145, 85);
    glVertex2i(145, 95);  // Top of window made closer to the roof
    glVertex2i(135, 95);
    glEnd();

    glBegin(GL_POLYGON);  // Rear window
    glVertex2i(155, 85);
    glVertex2i(165, 85);
    glVertex2i(165, 95);  // Top of window made closer to the roof
    glVertex2i(155, 95);
    glEnd();
}
// Function to draw the building
void drawBuilding() {
// Building body
    glColor3f(0.8, 0.8, 0.8);  // Light gray for the building
    glBegin(GL_POLYGON);
    glVertex2i(300, 80);  // Moved down from y = 150 to y = 100
    glVertex2i(510, 80);
    glVertex2i(510, 300);  // Moved down from y = 400 to y = 350
    glVertex2i(300, 300);
    glEnd();

// Windows of the building
glColor3f(0.0, 0.5, 1.0);  // Blue windows
for (int y = 280; y > 80; y -= 40) {  // Moved down by 20 units from y = 310 to y = 290
    for (int x = 310; x < 490; x += 40) {
        glBegin(GL_POLYGON);
        glVertex2i(x, y);
        glVertex2i(x + 30, y);
        glVertex2i(x + 30, y - 30);
        glVertex2i(x, y - 30);
        glEnd();
    }
}
    // Entrance of the building
    glColor3f(0.5, 0.5, 0.5);  // Darker gray for the entrance
    glBegin(GL_POLYGON);
    glVertex2i(350, 80);  // Moved down from y = 150 to y = 100
    glVertex2i(460, 80);
    glVertex2i(460, 120);  // Moved down from y = 200 to y = 150
    glVertex2i(350, 120);
    glEnd();
}

// Function to draw the road
void drawRoad() {
    // Road background
    glColor3f(0.2, 0.2, 0.2);  // Dark gray road
    glBegin(GL_POLYGON);
    glVertex2i(0, 80);
    glVertex2i(640, 80);
    glVertex2i(640, 0);
    glVertex2i(0, 0);
    glEnd();

    // Dashed white lines on the road
    glColor3f(1.0, 1.0, 1.0);  // White color for dashes
    for (int i = 0; i < 640; i += 50) {
        glBegin(GL_POLYGON);
        glVertex2i(i, 40);
        glVertex2i(i + 20, 40);
        glVertex2i(i + 20, 45);
        glVertex2i(i, 45);
        glEnd();
    }
}

// Function to draw the tree
void drawTree() {
    // Tree trunk
    glColor3f(0.4, 0.2, 0.0);  // Brown color for the trunk
    glBegin(GL_POLYGON);
    glVertex2i(230, 80);
    glVertex2i(240, 80);
    glVertex2i(240, 180);
    glVertex2i(230, 180);
    glEnd();

    // Tree foliage (three overlapping green circles)
    glColor3f(0.0, 0.8, 0.0);  // Green color for the foliage
    drawFilledCircle(225, 180, 30, 30);
    drawFilledCircle(245, 200, 30, 30);
    drawFilledCircle(265, 180, 30, 30);
}

// Display callback function
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the road, building, tree, and car
    drawRoad();
    drawBuilding();
    drawTree();
    drawCar();

    glFlush();
}

// Initialize OpenGL Graphics
void init() {
    glClearColor(0.6, 0.85, 1.0, 1.0);  // Set background to white
    glColor3f(0.0, 0.0, 0.0);          // Set drawing color to black
    glPointSize(4.0);                  // Set point size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);  // Set up 2D projection
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Realistic Building, Road, Tree, and Car");
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(50, 50);
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;
}
