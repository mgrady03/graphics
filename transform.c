#include <iostream>
#include <cmath>
#include <cstdlib>
#include <GL/gl.h>
#include <GL/glut.h>

// Global variables
GLfloat rotationAngle = 0.0f;

// Transformation matrix for rotation
GLfloat transformationMatrix[16] = {
    0.866f, -0.5f, 0.0f, 0.0f, // Rotation matrix for a 60-degree angle around the z-axis
    0.5f, 0.866f, 0.0f, 0.0f,
    0.0f, 0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 1.0f
};

// Timer function for animation
void timer(int value) {
    rotationAngle += 1.0f; // Increment rotation angle
    glutPostRedisplay(); // Trigger display function
    glutTimerFunc(16, timer, 0); // 60 FPS
}

// Display function
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Apply the transformation matrix (rotation)
    glMultMatrixf(transformationMatrix);

    // Draw your 3D object here
    // Replace the following lines with your actual object rendering code
    glColor3f(1.0f, 0.0f, 0.0f); // Set color to red
    glutSolidCube(1.0); // Example: render a red cube

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Simple OpenGL Animation");

    glEnable(GL_DEPTH_TEST); // Enable depth testing for 3D rendering

    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);

    glutMainLoop();
    return 0;
}
