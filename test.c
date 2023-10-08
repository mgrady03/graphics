#include <stdio.h>
#include "library.h"

int main(void){

    float s= 3.0;

    vec4 v1= {1,2,3,4};
    vec4 v2={5,6,7,8};

    mat4 m1={{1,5,9,13}, {2,6,10,14}, {3,7,11,15}, {4,8,12,16}};
    mat4 m2={{4,8,12,16},{3,7,11,15}, {2,6,10,14},{1,5,9,13}};



    ////////// vector testing /////////////

    vec4 product={0,0,0,0};
    scalarVectorMultiplication(s, &v1, &product);
    printf("Vector Scalar Product Multiplication: \n");
    printVector(&product); 

    printf("\n");

    vec4 sum={0,0,0,0};
    add(&v1, &v2, &sum);
    printf("Vector Addition: \n");
    printVector(&sum);

     printf("\n");

    vec4 difference={0,0,0,0};
    sub(&v1, &v2, &difference);
    printf("Vector Subtraction: \n");
    //printVector(&difference);
    printVector(sub(&v1, &v2, &difference));

     printf("\n");

    float mag = magnitude(&v1);
    printf("Vector Magnitude: \n");
    printf("%f",mag);

     printf("\n");
     printf("\n");

    vec4 norm={0,0,0,0};
    vec4 *l=normalize(mag, &v1, &norm);
    printf("Vector Normalize: \n");
    printVector(l);

    printf("\n");

    float dp = dotProduct(&v1, &v2);
    printf("Vector Dot Product: \n");
    printf("%f",dp);

    printf("\n");
    printf("\n");

    vec4 cp = {0,0,0,0};
    crossProduct(&v1, &v2, &cp);
    printf("Vector Dross Product: \n");
    printVector(&cp);

    printf("\n");
    printf("\n");

    ////////////////////////////////// matrix testing ////////////////////////////////

    mat4 sm= {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    scalarMatrixMultiplication(s, &m1, &sm);
    printf("Matrix Scalar Multiplication: \n");
    printMatrix(&sm);

    printf("\n");

    mat4 matrixSum={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    matrixAddition(&m1, &m2, &matrixSum);
    printf("Matrix Addition: \n");
    printMatrix(&matrixSum);

    printf("\n");

    mat4 matrixdifference= {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    matrixSubtraction(&m1, &m2, &matrixdifference);
    printf("Matrix Subtradtion: \n");
    printMatrix(&matrixdifference);

    printf("\n");

    mat4 p= {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    matrixMultiplication(&m1, &m2, &p);
    printf("Matrix Multiplication: \n");
    printMatrix(&p);

    printf("\n");

   mat4 inv = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    inverse(&inv);
    printf("Matrix Inverse: \n");
    printMatrix(&inv);

    printf("\n");

    mat4 tm= {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    transposeMatrix(&m1, &tm);
    printf("Matrix Transpose: \n");
    printMatrix(&tm);

    printf("\n");

    vec4 k= {0,0,0,0};
    matrixVectorMultiplication(&m1, &v1, &k);
    printf("Vector Matrix Multiplication: \n");
    printVector(&k);

    











}