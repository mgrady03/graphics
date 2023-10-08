#include <GL/glew.h>
#include <GL/glut.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include <chrono>

// Global variables
glm::mat4 modelMatrix = glm::mat4(1.0f);
bool isDragging = false;
glm::vec3 lastMousePos;
float scaleFactor = 1.0f;
bool isSpinning = false;
float spinSpeed = 1.0f; // Adjust the spin speed as needed
auto lastFrameTime = std::chrono::high_resolution_clock::now();

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            isDragging = true;
            lastMousePos = glm::vec3(x, y, 0);
        } else {
            isDragging = false;
        }
    }
}

void motion(int x, int y) {
    if (isDragging) {
        glm::vec3 currentMousePos(x, y, 0);
        glm::vec3 diff = currentMousePos - lastMousePos;

        // Calculate rotation axis and angle based on mouse movement
        float angle = glm::length(diff) * 0.01f;
        glm::vec3 rotationAxis = glm::cross(lastMousePos, currentMousePos);

        // Update the model matrix with the rotation
        modelMatrix = glm::rotate(modelMatrix, angle, rotationAxis);

        lastMousePos = currentMousePos;

        glutPostRedisplay();
    }
}

void mouseWheel(int wheel, int direction, int x, int y) {
    if (direction > 0) {
        // Scroll up, zoom in
        scaleFactor *= 1.02f;
    } else {
        // Scroll down, zoom out
        scaleFactor /= 1.02f;
    }

    // Apply the scaling to the model matrix
    modelMatrix = glm::scale(modelMatrix, glm::vec3(scaleFactor, scaleFactor, scaleFactor));

    glutPostRedisplay();
}

void spinObject() {
    auto currentTime = std::chrono::high_resolution_clock::now();
    float deltaTime = std::chrono::duration<float>(currentTime - lastFrameTime).count();
    lastFrameTime = currentTime;

    if (isSpinning) {
        // Rotate the object continuously
        modelMatrix = glm::rotate(modelMatrix, spinSpeed * deltaTime, glm::vec3(0.0f, 0.0f, 1.0f));
        glutPostRedisplay();
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    // Apply the model matrix
    glMultMatrixf(glm::value_ptr(modelMatrix));

    // Render your object here
    
    glutSwapBuffers();
}

void init() {
    glewInit();

    // Set up your shaders, camera, and other OpenGL settings

    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutMouseWheelFunc(mouseWheel);
    glutIdleFunc(spinObject); // Register the spinning callback
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Trackball Rotation, Zoom, and Spinning");

    glutDisplayFunc(display);
    init();

    glutMainLoop();
    return 0;
}
