
#ifndef library_h
#define library_h

#include<stdio.h>
#include<math.h>


typedef struct{

    float x;
    float y;
    float z;
    float w;
} vec4;


typedef struct{

    vec4 x;
    vec4 y;
    vec4 w;
    vec4 z;
} mat4;


void printVector(vec4* print);
vec4* scalarVectorMultiplication(float scalar, vec4* one, vec4* two);
vec4* add(vec4* one, vec4* two, vec4* sum);
vec4* sub(vec4* one, vec4* two, vec4* difference);
float magnitude(vec4* one);
vec4* normalize(float mag, vec4* one, vec4* result);
float dotProduct(vec4* one, vec4* two);   
vec4* crossProduct(vec4* one, vec4* two, vec4* result);

void printMatrix(mat4* one);
mat4* scalarMatrixMultiplication(float scalar, mat4* one,mat4* prouct);
mat4* matrixAddition(mat4* one, mat4* two, mat4* sum);
mat4* matrixSubtraction(mat4* one, mat4* two, mat4* difference);
mat4* matrixMultiplication(mat4* one, mat4* two, mat4* product);
float determinant3x3(float one[3][3]);
mat4* inverse(mat4* one);
mat4* transposeMatrix(mat4* one, mat4* result);
vec4* matrixVectorMultiplication(mat4* one, vec4* two, vec4* result);


#endif
