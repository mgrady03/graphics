#include <GL/glut.h>
#include <math.h>

// Define the number of sides of the cylinder
#define SIDES 20

void drawCylinder() {
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= SIDES; ++i) {
        float theta = (2.0f * M_PI * i) / SIDES;
        float x = cos(theta);
        float y = sin(theta);

        glVertex3f(x, y, 1.0f);  // Top circle
        glVertex3f(x, y, -1.0f); // Bottom circle
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0.0f, 0.0f, 1.0f); // Top center
    for (int i = 0; i <= SIDES; ++i) {
        float theta = (2.0f * M_PI * i) / SIDES;
        float x = cos(theta);
        float y = sin(theta);

        glVertex3f(x, y, 1.0f); // Top circle
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0.0f, 0.0f, -1.0f); // Bottom center
    for (int i = 0; i <= SIDES; ++i) {
        float theta = (2.0f * M_PI * i) / SIDES;
        float x = cos(theta);
        float y = sin(theta);

        glVertex3f(x, y, -1.0f); // Bottom circle
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glColor3f(0.5f, 0.5f, 1.0f); // Set color to blue
    glRotatef(45.0f, 1.0f, 0.0f, 0.0f); // Rotate the cylinder

    drawCylinder();

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (GLfloat)w / (GLfloat)h, 1.0f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -5.0f); // Move the camera back
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Cylinder in OpenGL");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glEnable(GL_DEPTH_TEST);

    glutMainLoop();

    return 0;
}
