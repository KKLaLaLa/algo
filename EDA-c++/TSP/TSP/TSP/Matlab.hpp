//
//  Matlab.hpp
//  TSP
//
//  Created by 王昆 on 2020/3/10.
//  Copyright © 2020 昆. All rights reserved.
//

#ifndef Matlab_hpp
#define Matlab_hpp

#include <stdio.h>

extern int Matlabindex;
extern int *MatlabindexSub;

int *findmax(float *input,int compare,int length);
int *findmin(float *input,int compare,int length);
int Matmax(float *input,int length);
int Matmin(float *input,int length);

int *findmax(int *input,float compare,int length);
int *findmin(int *input,float compare,int length);
int Matmax(int *input,int length);
int Matmin(int *input,int length);
int *cumsum(int *input, int length);
int *Matsort(int *input, int length, int mode);
float *Matsort(float *input, int length, int mode);
//int size(float input[row][col],int length,int mode);

#endif /* Matlab_hpp */
