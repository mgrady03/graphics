#include <GL/glew.h>
#include <GL/glut.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
#include <iostream>
#include <cmath>

GLuint VAO, VBO;
GLuint shaderProgram;
int numTorusVertices;

void createTorus(float outerRadius, float innerRadius, int numSegments, int numRings) {
    std::vector<GLfloat> vertices;

    for (int i = 0; i <= numRings; ++i) {
        float phi = 2.0f * glm::pi<float>() * static_cast<float>(i) / numRings;
        for (int j = 0; j <= numSegments; ++j) {
            float theta = 2.0f * glm::pi<float>() * static_cast<float>(j) / numSegments;

            float x = (outerRadius + innerRadius * cos(theta)) * cos(phi);
            float y = (outerRadius + innerRadius * cos(theta)) * sin(phi);
            float z = innerRadius * sin(theta);

            vertices.push_back(x);
            vertices.push_back(y);
            vertices.push_back(z);
        }
    }

    numTorusVertices = static_cast<int>(vertices.size() / 3);

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat), vertices.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glUseProgram(shaderProgram);

    glm::mat4 model;
    glm::mat4 view;
    glm::mat4 projection;

    // Set up your model, view, and projection matrices here

    glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
    glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));

    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, numTorusVertices);
    glBindVertexArray(0);

    glutSwapBuffers();
}

void init() {
    glewInit();

    // Create shader program and compile shaders
    // Set up your camera and view transformations
    // Initialize matrices and shaders as needed

    createTorus(1.0f, 0.3f, 50, 50); // Adjust the outer and inner radii, number of segments, and rings as needed
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Torus Rendering");

    glutDisplayFunc(display);
    init();

    glutMainLoop();
    return 0;
}
