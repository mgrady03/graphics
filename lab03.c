/*#ifdef __APPLE__  // include Mac OS X verions of headers
//#include <OpenGL/OpenGL.h>
#include <OpenGL/gl3.h>
#include <GLUT/glut.h>
#include <OpenGL/OpenGL.h>
//#include <GLFW/glfw3.h>
#else // non-Mac OS X operating systems

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/freeglut_ext.h>

#endif  // __APPLE__

//#include "initShader.h"
#include "../mylib/initShader.h"
#include <stdio.h>
//#include "../mylib/library.h"
#include "../mylib/library.h"
#include <math.h>
#include <time.h>
#include <stdlib.h>


#define BUFFER_OFFSET( offset )   ((GLvoid*) (offset))

const float DegreesToRadians = M_PI / 180.0; //pi duh bc stupid trig
//conversion to rad bc math not work in degrees.
mat4 m1={{1,0,0,0}, {0, 0.71, -0.71, 0}, {0, 0.71, 0.71, 0,}, {0,0,0,1}};

vec4 vertices[222]; //bring me luck 222
vec4 result[222];
vec4 temp;

void initVertices() //initialize vertices--check lib func
{
    int k = 0; //k for vert, increase per s


    for (float p = -180; p <= 180.0; p += 10.0){

        float r = p * DegreesToRadians;
        float r2 = (p + 10) * DegreesToRadians;

        //maybe?
        
    
        

        vertices[k].x = 0;
        vertices[k].y = 0.9;
        vertices[k].z = 0;
        vertices[k].w = 1.0;//
        //matrixVectorMultiplication(&m1, &vertices[k], &temp);
        //vertices[k]=temp;
        k++;




        vertices[k].x = 0.45 * cos(r2);//-->sin or cos
        vertices[k].y = 0;
        vertices[k].z = 0.45 * sin(r2); //-> sin or cos
        vertices[k].w = 1.0;//
        //matrixVectorMultiplication(&m1, &vertices[k], &temp);
        //vertices[k]=temp;
        k++;

 


        vertices[k].x = 0.45 * cos(r);//-->sin or cos
        vertices[k].y = 0;
        vertices[k].z = 0.45 * sin(r);//-->sin or cos
        vertices[k].w = 1.0;//
        //matrixVectorMultiplication(&m1, &vertices[k], &temp);
        //vertices[k]=temp;
        k++;   


        vertices[k].x = 0.45 * cos(r2);//-->sin or cos
        vertices[k].y = 0;
        vertices[k].z = 0.45 * sin(r2);//-->sin or cos
        vertices[k].w = 1.0;//
        //matrixVectorMultiplication(&m1, &vertices[k], &temp);
        //vertices[k]=temp;
        k++;



        vertices[k].x = 0.45 * cos(r);//-->sin or cos
        vertices[k].y = 0;
        vertices[k].z = 0.45 * sin(r);//-->sin or cos
        vertices[k].w = 1.0;//
        //matrixVectorMultiplication(&m1, &vertices[k], &temp);
        //vertices[k]=temp;
        k++;

        
 

        vertices[k].x = 0;
        vertices[k].y = 0;
        vertices[k].z = 0;
        vertices[k].w = 1.0;//remain same
        //matrixVectorMultiplication(&m1, &vertices[k], &temp);
        //vertices[k]=temp;
        k++;


    }

}



vec4 colors[222];//colors for triangles 
void initColors()
{
    for(int i = 0; i < 222; i=i+3) //+3 for tri, 222 for num of vert 
    {
        colors[i].x = colors[i+1].x = colors[i+2].x = rand() / (float)RAND_MAX;
        colors[i].y = colors[i+1].y = colors[i+2].y = rand() / (float)RAND_MAX;
        colors[i].z = colors[i+1].z = colors[i+2].z = rand() / (float)RAND_MAX;
        colors[i].w = 1.0;
    }
}

//222 bc it means good fortune and i need that 
int num_vertices = 222;




GLuint program;

void init(void)
{
  

    GLuint program = initShader("./vshader.glsl", "./fshader.glsl");
    glUseProgram(program);
    
    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    
    GLuint buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices) + sizeof(colors), NULL, GL_STATIC_DRAW);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
    glBufferSubData(GL_ARRAY_BUFFER, sizeof(vertices), sizeof(colors), colors);
    
    GLuint vPosition = glGetAttribLocation(program, "vPosition");
    glEnableVertexAttribArray(vPosition);
    glVertexAttribPointer(vPosition, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
    
    GLuint vColor = glGetAttribLocation(program, "vColor");
    glEnableVertexAttribArray(vColor);
    glVertexAttribPointer(vColor, 4, GL_FLOAT, GL_FALSE, 0, (GLvoid *) sizeof(vertices));
    
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glDepthRange(1,0);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glPolygonMode(GL_FRONT, GL_FILL);
    glPolygonMode(GL_BACK, GL_LINE);
    glDrawArrays(GL_TRIANGLES, 0, num_vertices);
    
    glutSwapBuffers();
}




void keyboard(unsigned char key, int mousex, int mousey)
{
    if(key == 'q')
        exit(0);
    
    glutPostRedisplay();
}

int main(int argc, char **argv)
{

    initVertices();
    initColors();
  
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(512, 512);
    glutInitWindowPosition(250,250);
    glutCreateWindow("Lab3 cone");

    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    
    return 0;
}*/

#ifdef __APPLE__  // Include Mac OS X versions of headers
#include <OpenGL/gl3.h>
#include <GLUT/glut.h>
#else // Non-Mac OS X operating systems
#include <GL/glew.h>
#include <GL/freeglut.h>
#endif  // __APPLE__

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

#define BUFFER_OFFSET(offset) ((GLvoid *)(offset))

const float DegreesToRadians = M_PI / 180.0;

typedef struct {
    GLfloat x, y, z, w;
} vec4;

typedef struct {
    GLfloat x, y, z;
} vec3;

typedef struct {
    vec4 x, y, z, w;
} mat4;

mat4 m1 = {{1, 0, 0, 0}, {0, 0.71, -0.71, 0}, {0, 0.71, 0.71, 0}, {0, 0, 0, 1}};

vec4 vertices[444]; // 222 vertices for the cone and 222 for the cylinder
vec4 colors[444];  // Colors for triangles
int num_vertices = 444; // Total number of vertices

void initVertices() {
    int k = 0; // Vertex index

    // Initialize vertices for the cone
    for (float p = -180; p <= 180.0; p += 10.0) {
        float r = p * DegreesToRadians;
        float r2 = (p + 10) * DegreesToRadians;

        vertices[k].x = 0;
        vertices[k].y = 0.9;
        vertices[k].z = 0;
        vertices[k].w = 1.0;
        k++;

        vertices[k].x = 0.45 * cos(r2);
        vertices[k].y = 0;
        vertices[k].z = 0.45 * sin(r2);
        vertices[k].w = 1.0;
        k++;

        vertices[k].x = 0.45 * cos(r);
        vertices[k].y = 0;
        vertices[k].z = 0.45 * sin(r);
        vertices[k].w = 1.0;
        k++;

        vertices[k].x = 0.45 * cos(r2);
        vertices[k].y = 0;
        vertices[k].z = 0.45 * sin(r2);
        vertices[k].w = 1.0;
        k++;

        vertices[k].x = 0.45 * cos(r);
        vertices[k].y = 0;
        vertices[k].z = 0.45 * sin(r);
        vertices[k].w = 1.0;
        k++;

        vertices[k].x = 0;
        vertices[k].y = 0;
        vertices[k].z = 0;
        vertices[k].w = 1.0;
        k++;
    }

    // Initialize vertices for the cylinder
    for (float p = -180; p <= 180.0; p += 10.0) {
        float r = p * DegreesToRadians;
        float r2 = (p + 10) * DegreesToRadians;

        vertices[k].x = 0.45 * cos(r);
        vertices[k].y = 0.9;
        vertices[k].z = 0.45 * sin(r);
        vertices[k].w = 1.0;
        k++;

        vertices[k].x = 0.45 * cos(r2);
        vertices[k].y = 0.9;
        vertices[k].z = 0.45 * sin(r2);
        vertices[k].w = 1.0;
        k++;

        vertices[k].x = 0.45 * cos(r);
        vertices[k].y = -0.9;
        vertices[k].z = 0.45 * sin(r);
        vertices[k].w = 1.0;
        k++;

        vertices[k].x = 0.45 * cos(r2);
        vertices[k].y = -0.9;
        vertices[k].z = 0.45 * sin(r2);
        vertices[k].w = 1.0;
        k++;
    }
}

void initColors() {
    for (int i = 0; i < num_vertices; i++) {
        colors[i].x = rand() / (float)RAND_MAX;
        colors[i].y = rand() / (float)RAND_MAX;
        colors[i].z = rand() / (float)RAND_MAX;
        colors[i].w = 1.0;
    }
}

GLuint program;


void init(void) {
    program = initShader("./vshader.glsl", "./fshader.glsl");
    glUseProgram(program);

    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    GLuint buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices) + sizeof(colors), NULL, GL_STATIC_DRAW);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
    glBufferSubData(GL_ARRAY_BUFFER, sizeof(vertices), sizeof(colors), colors);

    GLuint vPosition = glGetAttribLocation(program, "vPosition");
    glEnableVertexAttribArray(vPosition);
    glVertexAttribPointer(vPosition, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

    GLuint vColor = glGetAttribLocation(program, "vColor");
    glEnableVertexAttribArray(vColor);
    glVertexAttribPointer(vColor, 4, GL_FLOAT, GL_FALSE, 0, (GLvoid *)sizeof(vertices));

    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glDepthRange(1, 0);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Draw the cone
    glPolygonMode(GL_FRONT, GL_FILL);
    glPolygonMode(GL_BACK, GL_LINE);
    glDrawArrays(GL_TRIANGLES, 0, num_vertices / 2); // Draw only the first half (cone)

    // Draw the cylinder
    glPolygonMode(GL_FRONT, GL_FILL);
    glPolygonMode(GL_BACK, GL_LINE);
    glDrawArrays(GL_TRIANGLES, num_vertices / 2, num_vertices / 2); // Draw the second half (cylinder)

    glutSwapBuffers();
}

void keyboard(unsigned char key, int mousex, int mousey) {
    if (key == 'q')
        exit(0);

    glutPostRedisplay();
}

int main(int argc, char **argv) {
    initVertices();
    initColors();

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(512, 512);
    glutInitWindowPosition(250, 250);
    glutCreateWindow("Lab3 cone and cylinder");

    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();

    return 0;
}


