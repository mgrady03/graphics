#include "library.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>



void printVector(vec4 *p){
    float x=p->x;
    float y= p->y;
    float i=p->z;
    float j=p->w;


    printf("[%.2f %.2f %.2f %.2f]\n", x, y, i, j);
}

vec4* scalarVectorMultiplication(float scalar, vec4* one, vec4* product){

    float x = scalar * one->x;
    float y = scalar * one->y;
    float i = scalar * one->w;
    float j = scalar * one->z;

    product->x = x;
    product->y = y;
    product->w = i;
    product->z = j;
    
    return product;
}

vec4* add(vec4* one, vec4* two, vec4* sum ){

       float x= one->x + two->x;
       float y= one->y + two->y;
       float i= one->w + two->w;
       float j= one->z + two->z;

       sum-> x= x;
       sum->y = y;
       sum->w = i;
       sum->z = j;

       return sum;

        
}

vec4* sub(vec4* one, vec4* two, vec4* difference){

    float x= one->x - two->x;
    float y= one->y - two->y;
    float i= one->w - two->w;
    float j= one->z - two->z;

    difference->x= x;
    difference->y = y;
    difference->w = i;
    difference->z = j;

    return difference;

}

float magnitude(vec4* one){
    float x= one->x;
    float y= one->y;
    float i= one->w;
    float j= one->z;

    float result= sqrt((x*x)+(y*2)+(i*2)+(j*2));

    return result;

}

vec4* normalize( float mag, vec4* one, vec4 *result){
    scalarVectorMultiplication(mag, one, result);

    return result;
}

float dotProduct(vec4* one, vec4* two){

    float result = ((one->x * two->x)+(one->y * two->y)+(one->w * two->w)+(one->z * two->z));

    return result;
}

vec4* crossProduct(vec4* one, vec4* two, vec4* result){
    float x = one->x * two->w - one->w * two->y;
    float y = one->w * two->x - one->x * two->w;
    float i = one->x * two->y - one->y * two->x;
    float j = one->x * two->y - one->y * two->x;

    result->x = x;
    result->y = y;
    result->w = i;
    result->z = j;

    return result;
}


    /////////////////////////////////////////////////// Matrix ////////////////////////////////////////


void printMatrix( mat4* one){

    printf("|%.2f  %.2f  %.2f  %.2f| \n",one->x.x,one->y.x,one->w.x,one->z.x);
    printf("|%.2f  %.2f  %.2f  %.2f|\n",one->x.y,one->y.y,one->w.y,one->z.y);
    printf("|%.2f  %.2f  %.2f  %.2f|\n",one->x.w,one->y.w,one->w.w,one->z.w);
    printf("|%.2f  %.2f  %.2f  %.2f|\n",one->x.z,one->y.z,one->w.z,one->z.z);

}

mat4* scalarMatrixMultiplication(float scalar, mat4* one, mat4* product){

    product->x.x = scalar * one->x.x;
    product->y.x = scalar * one->y.x;
    product->w.x = scalar * one->w.x;
    product->z.x = scalar * one->z.x;

    product->x.y = scalar * one->x.y;
    product->y.y = scalar * one->y.y;
    product->w.y = scalar * one->w.y;
    product->z.y = scalar * one->z.y;

    product->x.w = scalar * one->x.w;
    product->y.w = scalar * one->y.w;
    product->w.w = scalar * one->w.w;
    product->z.w = scalar * one->z.w;

    product->x.z = scalar * one->x.z;
    product->y.z = scalar * one->y.z;
    product->w.z = scalar * one->w.z;
    product->z.z = scalar * one->z.z;

    return product;
}

mat4* matrixAddition(mat4* one, mat4* two, mat4* sum){

    sum->x.x = one->x.x + two->x.x;
    sum->y.x = one->y.x + two->y.x;
    sum->w.x = one->w.x + two->w.x;
    sum->z.x = one->z.x + two->z.x;

    sum->x.y = one->x.y + two->x.y;
    sum->y.y = one->y.y + two->y.y;
    sum->w.y = one->w.y + two->w.y;
    sum->z.y = one->z.y + two->z.y;

    sum->x.w = one->x.w + two->x.w;
    sum->y.w = one->y.w + two->y.w;
    sum->w.w = one->w.w + two->w.w;
    sum->z.w = one->z.w + two->z.w;

    sum->x.z = one->x.z + two->x.z;
    sum->y.z = one->y.z + two->y.z;
    sum->w.z = one->w.z + two->w.z;
    sum->z.z = one->z.z + two->z.z;

    return sum;
}

mat4* matrixSubtraction(mat4* one, mat4* two, mat4* difference){

    difference->x.x = one->x.x - two->x.x;
    difference->y.x = one->y.x - two->y.x;
    difference->w.x = one->w.x - two->w.x;
    difference->z.x = one->z.x - two->z.x;

    difference->x.y = one->x.y - two->x.y;
    difference->y.y = one->y.y - two->y.y;
    difference->w.y = one->w.y - two->w.y;
    difference->z.y = one->z.y - two->z.y;

    difference->x.w = one->x.w - two->x.w;
    difference->y.w = one->y.w - two->y.w;
    difference->w.w = one->w.w - two->w.w;
    difference->z.w = one->z.w - two->z.w;

    difference->x.z = one->x.z - two->x.z;
    difference->y.z = one->y.z - two->y.z;
    difference->w.z = one->w.z - two->w.z;
    difference->z.z = one->z.z - two->z.z;

    return difference;


}

mat4* matrixMultiplication(mat4* one, mat4* two, mat4* product){

     product->x.x = (one->x.x * two->x.x) + (one->x.y * two->y.x) + (one->x.w * two->w.x) + (one->x.z * two->z.x);
     product->y.x = (one->y.x * two->x.x) + (one->y.y * two->y.x) + (one->y.w * two->w.x) + (one->y.z * two->z.x);
     product->w.x = (one->w.x * two->x.x) + (one->w.y * two->y.x) + (one->w.y * two->w.x) + (one->w.z * two->z.x);
     product->z.x = (one->z.x + two->x.x) + (one->z.y * two->y.x) + (one->z.y * two->w.x) + (one->z.z * two->z.x);

     product->x.y = (one->x.x * two->x.y) + (one->x.y * two->y.y) + (one->x.w * two->w.y) + (one->x.z * two->z.y);
     product->y.y = (one->y.x * two->x.y) + (one->y.y * two->y.y) + (one->y.w * two->w.y) + (one->y.z * two->z.y);
     product->w.y = (one->w.x * two->x.y) + (one->w.y * two->y.y) + (one->w.y * two->w.y) + (one->w.z * two->z.y);
     product->z.y = (one->z.x + two->x.y) + (one->z.y * two->y.y) + (one->z.y * two->w.y) + (one->z.z * two->z.y);

     product->x.w = (one->x.x * two->x.w) + (one->x.y * two->y.w) + (one->x.w * two->w.w) + (one->x.z * two->z.w);
     product->y.w = (one->y.x * two->x.w) + (one->y.y * two->y.w) + (one->y.w * two->w.w) + (one->y.z * two->z.w);
     product->w.w = (one->w.x * two->x.w) + (one->w.y * two->y.w) + (one->w.y * two->w.w) + (one->w.z * two->z.w);
     product->z.w = (one->z.x + two->x.w) + (one->z.y * two->y.w) + (one->z.y * two->w.w) + (one->z.z * two->z.w);

     product->x.z = (one->x.x * two->x.z) + (one->x.y * two->y.z) + (one->x.w * two->w.z) + (one->x.z * two->z.z);
     product->y.z = (one->y.x * two->x.z) + (one->y.y * two->y.z) + (one->y.w * two->w.z) + (one->y.z * two->z.z);
     product->w.z = (one->w.x * two->x.z) + (one->w.y * two->y.z) + (one->w.y * two->w.z) + (one->w.z * two->z.z);
     product->z.z = (one->z.x + two->x.z) + (one->z.y * two->y.z) + (one->z.y * two->w.z) + (one->z.z * two->z.z);


     return product;
}

vec4* getCofactor(mat4* mat, int p, int q) {
    vec4 result;
    int i = 0, j = 0;

    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {
            if (row != p && col != q) {
                switch (i * 4 + j) {
                    case 0: result.x = mat.x.x; break;
                    case 1: result.x = mat.y.x; break;
                    case 2: result.x = mat.z.x; break;
                    case 3: result.x = mat.w.x; break;
                    case 4: result.y = mat.x.y; break;
                    case 5: result.y = mat.y.y; break;
                    case 6: result.y = mat.z.y; break;
                    case 7: result.y = mat.w.y; break;
                    case 8: result.z = mat.x.z; break;
                    case 9: result.z = mat.y.z; break;
                    case 10: result.z = mat.z.z; break;
                    case 11: result.z = mat.w.z; break;
                    case 12: result.w = mat.x.w; break;
                    case 13: result.w = mat.y.w; break;
                    case 14: result.w = mat.z.w; break;
                    case 15: result.w = mat.w.w; break;
                }
                j++;
                if (j == 4) {
                    j = 0;
                    i++;
                }
            }
        }
    }
    return result;
}

float determinant(mat4* mat) {
    float det = 0;
    int sign = 1;

    for (int f = 0; f < 4; f++) {
        vec4 cofactor = getCofactor(mat, 0, f);
        switch (f) {
            case 0: det += sign * mat.x.x * determinant(mat); break;
            case 1: det += sign * mat.x.y * determinant(mat); break;
            case 2: det += sign * mat.x.z * determinant(mat); break;
            case 3: det += sign * mat.x.w * determinant(mat); break;
        }
        sign = -sign;
    }
    return det;
}

mat4* adjoint(mat4* mat) {
    mat4 adj;
    int sign = 1;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            vec4* cofactor = getCofactor(mat, i, j);
            switch (i * 4 + j) {
                case 0: adj.x.x = sign * determinant(cofactor); break;
                case 1: adj.x.y = sign * determinant(cofactor); break;
                case 2: adj.x.z = sign * determinant(cofactor); break;
                case 3: adj.x.w = sign * determinant(cofactor); break;
                case 4: adj.y.x = sign * determinant(cofactor); break;
                case 5: adj.y.y = sign * determinant(cofactor); break;
                case 6: adj.y.z = sign * determinant(cofactor); break;
                case 7: adj.y.w = sign * determinant(cofactor); break;
                case 8: adj.z.x = sign * determinant(cofactor); break;
                case 9: adj.z.y = sign * determinant(cofactor); break;
                case 10: adj.z.z = sign * determinant(cofactor); break;
                case 11: adj.z.w = sign * determinant(cofactor); break;
                case 12: adj.w.x = sign * determinant(cofactor); break;
                case 13: adj.w.y = sign * determinant(cofactor); break;
                case 14: adj.w.z = sign * determinant(cofactor); break;
                case 15: adj.w.w = sign * determinant(cofactor); break;
            }
            sign = -sign;
        }
    }
    return adj;
}





mat4* inverse(mat4* mat){

    float det = determinant(mat);
    if (det == 0) {
        printf("Matrix is not invertible.\n");
        return mat;
    }
    
    mat4 adj = adjoint(mat);
    mat4 inv;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            switch (i * 4 + j) {
                case 0: inv.x.x = adj.x.x / det; break;
                case 1: inv.x.y = adj.x.y / det; break;
                case 2: inv.x.z = adj.x.z / det; break;
                case 3: inv.x.w = adj.x.w / det; break;
                case 4: inv.y.x = adj.y.x / det; break;
                case 5: inv.y.y = adj.y.y / det; break;
                case 6: inv.y.z = adj.y.z / det; break;
                case 7: inv.y.w = adj.y.w / det; break;
                case 8: inv.z.x = adj.z.x / det; break;
                case 9: inv.z.y = adj.z.y / det; break;
                case 10: inv.z.z = adj.z.z / det; break;
                case 11: inv.z.w = adj.z.w / det; break;
                case 12: inv.w.x = adj.w.x / det; break;
                case 13: inv.w.y = adj.w.y / det; break;
                case 14: inv.w.z = adj.w.z / det; break;
                case 15: inv.w.w = adj.w.w / det; break;
            }
        }
    }
    return inv;
}







/*
    //https://www.mathsisfun.com/algebra/matrix-inverse.html
    //https://www.geeksforgeeks.org/inverse-of-a-matrix/

    float determinant;
    determinant = one->x.x * ((one->y.y * one->w.w * one->z.z) + (one->w.y * one->z.w * one->y.z) + (one->z.y * one->y.w * one->w.z)- (one->y.y * one->z.w * one->w.z) - (one->w.y * one->y.w * one->z.z) - (one->z.y * one->w.w * one->y.z)) + one->y.x * ((one->x.y * one->z.w * one->w.z) + (one->w.y * one->x.w * one->z.z) + (one->z.y * one->w.w * one->x.z)- (one->x.y * one->w.w * one->z.z) - (one->w.y * one->z.w * one->x.z) - (one->z.y * one->x.w * one->w.z))+ one->w.x * ((one->x.y * one->y.w * one->z.z) + (one->y.y * one->z.w * one->x.z) + (one->z.y * one->x.w * one->y.z)- (one->x.y * one->z.w * one->y.z) - (one->y.y * one->x.w * one->z.z) - (one->z.y * one->y.w * one->x.z))+ one->z.x * ((one->x.y * one->w.w * one->y.z) + (one->y.y * one->x.w * one->w.z) + (one->w.y * one->y.w * one->x.z)- (one->x.y * one->y.w * one->w.z) - (one->y.y * one->w.w * one->x.z) - (one->w.y * one->x.w * one->y.z));

        if(determinant == 0){
            return result;
         }




    mat4 inDATverse={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};

    inDATverse.x.x = (one->y.y * one->w.w * one->z.z) + (one->w.y * one->z.w * one->y.z) + (one->z.y * one->y.w * one->w.z) - (one->y.y * one->z.w * one->w.z) - (one->w.y * one->y.w * one->z.z) - (one->z.y * one->w.w * one->y.z);
    inDATverse.x.y = -((one->y.x * one->w.w * one->z.z) + (one->w.x * one->z.w * one->y.z) + (one->z.x * one->y.w * one->w.z)- (one->y.x * one->z.w * one->w.z) - (one->w.x * one->y.w * one->z.z) - (one->z.x * one->w.w * one->y.z));
    inDATverse.x.w = (one->y.x * one->w.y * one->z.z) + (one->w.x * one->z.y * one->y.z) + (one->z.x * one->y.y * one->w.z)- (one->y.x * one->z.y * one->w.z) - (one->w.x * one->y.y * one->z.z) - (one->z.x * one->w.y * one->y.z);
    inDATverse.x.z = - ((one->y.x * one->w.y * one->z.w) + (one->w.x * one->z.y * one->y.w) + (one->z.x * one->y.y * one->w.w)- (one->y.x * one->z.y * one->w.w) - (one->w.x * one->y.y * one->z.w) - (one->z.x * one->w.y * one->y.w));
  
    inDATverse.y.x = - ((one->x.y * one->w.w * one->z.z) + (one->w.y * one->z.w * one->x.z) + (one->z.y * one->x.w * one->w.z) - (one->x.y * one->z.w * one->w.z) - (one->w.y * one->x.w * one->z.z) - (one->z.y * one->w.w * one->x.z));
    inDATverse.y.y = (one->x.x * one->w.w * one->z.z) + (one->w.x * one->z.w * one->x.z) + (one->z.x * one->x.w * one->w.z)- (one->x.x * one->z.w * one->w.z) - (one->w.x * one->x.w * one->z.z) - (one->z.x * one->w.w * one->x.z);
    inDATverse.y.w = - ((one->x.x * one->w.y * one->z.z) + (one->w.x * one->z.y * one->x.z) + (one->z.x * one->x.y * one->w.z)- (one->x.x * one->z.y * one->w.z) - (one->w.x * one->x.y * one->z.z) - (one->z.x * one->w.y * one->x.z));
    inDATverse.y.z = (one->x.x * one->w.y * one->z.w) + (one->w.x * one->z.y * one->x.w) + (one->z.x * one->x.y * one->w.w)- (one->x.x * one->z.y * one->w.w) - (one->w.x * one->x.y * one->z.w) - (one->z.x * one->w.y * one->x.w);

    inDATverse.w.x = (one->x.y * one->y.w * one->z.z) + (one->y.y * one->z.w * one->x.z) + (one->z.y * one->x.w * one->y.z) - (one->x.y * one->z.w * one->y.z) - (one->y.y * one->x.w * one->z.z) - (one->z.y * one->y.w * one->x.z);
    inDATverse.w.y = - ((one->x.x * one->y.w * one->z.z) + (one->y.x * one->z.w * one->x.z) + (one->z.x * one->x.w * one->y.z) - (one->x.x * one->z.w * one->y.z) - (one->y.x * one->x.w * one->z.z) - (one->z.x * one->y.w * one->x.z));
    inDATverse.w.w = (one->x.x * one->y.y * one->z.z) + (one->y.x * one->z.y * one->x.z) + (one->z.x * one->x.y * one->y.z)- (one->x.x * one->z.y * one->y.z) - (one->y.x * one->x.y * one->z.z) - (one->z.x * one->y.y * one->x.z);
    inDATverse.w.z = - ((one->x.x * one->y.y * one->z.w) + (one->y.x * one->z.y * one->x.w) + (one->z.x * one->x.y * one->y.w) - (one->x.x * one->z.y * one->y.w) - (one->y.x * one->x.y * one->z.w) - (one->z.x * one->y.y * one->x.w));

    inDATverse.z.x = - ((one->x.y * one->y.w * one->w.z) + (one->y.y * one->w.w * one->x.z) + (one->w.y * one->x.w * one->y.z)- (one->x.y * one->y.z * one->w.w) - (one->y.y * one->x.w * one->w.z) - (one->w.y * one->y.w * one->x.z));
    inDATverse.z.y = (one->x.x * one->y.w * one->w.z) + (one->y.x * one->w.w * one->x.z) + (one->w.x * one->x.w * one->y.z)- (one->x.x * one->w.w * one->y.z) - (one->y.x * one->x.w * one->w.z) - (one->w.x * one->y.w * one->x.z);
    inDATverse.z.w = - ((one->x.x * one->y.y * one->w.z) + (one->y.x * one->w.y * one->x.z) + (one->w.x * one->x.y * one->y.z)- (one->x.x * one->w.y * one->y.z) - (one->y.x * one->x.y * one->w.z) - (one->w.x * one->y.y * one->x.z));
    inDATverse.z.z = (one->x.x * one->y.y * one->w.w) + (one->y.x * one->w.y * one->x.w) + (one->w.x * one->x.y * one->y.w)- (one->x.x * one->w.y * one->y.w) - (one->y.x * one->x.y * one->w.w) - (one->w.x * one->y.y * one->x.w);


    transposeMatrix(&inDATverse, &inDATverse);
    return scalarMatrixMultiplication((1/determinant), &inDATverse, result);



}*/

mat4* transposeMatrix(mat4* one, mat4* result){

    mat4 num[16];

    for(int i=0; i<=15; i++){
        num[i]=one[i];
    }

    result->x.x = num->x.x;
    result->y.x = num->x.y;
    result->w.x = num->x.w;
    result->z.x = num->x.z;

    result->x.y = num->y.x;
    result->y.y = num->y.y;
    result->w.y = num->y.w;
    result->z.y = num->y.z;

    result->x.w = num->w.x;
    result->y.w = num->w.y;
    result->w.w = num->w.w;
    result->z.w = num->w.z;

    result->x.z = num->z.x;
    result->y.z = num->z.y;
    result->w.z = num->z.w;
    result->z.z = num->z.z;

    return result; 
}

vec4* matrixVectorMultiplication(mat4* one, vec4* two, vec4* result){

    float x = (one->x.x * two->x) + (one->y.x * two->x) + (one->w.x * two->x) + (one->z.x * two->x);
    float y = (one->x.y * two->y) + (one->y.y * two->y) + (one->w.y * two->y) + (one->z.y * two->y);
    float i = (one->x.w * two->w) + (one->y.w * two->w) + (one->w.w * two->w) + (one->z.w * two->w);
    float j = (one->x.z * two->z) + (one->y.z * two->z) + (one->w.z * two->z) + (one->z.z * two->z);

    result->x = x;
    result->y = y;
    result->w = i;
    result->z = j;

    return result;
}