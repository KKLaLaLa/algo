//
//  Matlab.cpp
//  TSP
//
//  Created by 王昆 on 2020/3/10.
//  Copyright © 2020 昆. All rights reserved.
//

#include "Matlab.hpp"

int *findmax(float *input,int compare,int length)
{
int value_flag[length];
int val_number = 0;
int *returnmatix;
for(int i = 0; i < length; i++) {
    value_flag[i] = 0;
    if(input[i] > compare) {
        val_number++;
        value_flag[i] = 1;
    }
}
returnmatix = new int(val_number);
int j = 0;
for (int i = 0; i < length; i++) {
    if (value_flag[i] == 1) {
        returnmatix[j] = i;
        j++;
    }
}
Matlabindex = val_number;
return returnmatix;
}
int *findmax(int *input,float compare,int length)
{
int value_flag[length];
int val_number = 0;
int *returnmatix;
for(int i = 0; i < length; i++) {
    value_flag[i] = 0;
    if(input[i] > compare) {
        val_number++;
        value_flag[i] = 1;
    }
}
returnmatix = new int(val_number);
int j = 0;
for (int i = 0; i < length; i++) {
    if (value_flag[i] == 1) {
        returnmatix[j] = i;
        j++;
    }
}
Matlabindex = val_number;
return returnmatix;
}
int *findmin(float *input,int compare,int length)
{
    int value_flag[length];
    int val_number = 0;
    int *returnmatix;

    for(int i = 0; i < length; i++) {
        value_flag[i] = 0;
        if(input[i] < compare) {
            val_number++;
            value_flag[i] = 1;
        }
    }
    returnmatix = new int(val_number);
    int j = 0;
    for (int i = 0; i < length; i++) {
        if (value_flag[i] == 1) {
            returnmatix[j] = i;
            j++;
        }
    }
    Matlabindex = val_number;
    return returnmatix;
}
int *findmin(float *input,double compare,int length)
{
    int value_flag[length];
    int val_number = 0;
    int *returnmatix;

    for(int i = 0; i < length; i++) {
        value_flag[i] = 0;
        if(input[i] < compare) {
            val_number++;
            value_flag[i] = 1;
        }
    }
    returnmatix = new int(val_number);
    int j = 0;
    for (int i = 0; i < length; i++) {
        if (value_flag[i] == 1) {
            returnmatix[j] = i;
            j++;
        }
    }
    Matlabindex = val_number;
    return returnmatix;
}
int Matmax(float *input,int length){
    int maxofmat = input[0];
    Matlabindex = 0;
    for (int i = 1; i < length; i++) {
        if(maxofmat < input[i]){
            maxofmat = input[i];
            Matlabindex = i;
        }
    }
    return maxofmat;
}
int Matmax(int *input,int length){
    int maxofmat = input[0];
    Matlabindex = 0;
    for (int i = 1; i < length; i++) {
        if(maxofmat < input[i]){
            maxofmat = input[i];
            Matlabindex = i;
        }
    }
    return maxofmat;
}
int Matmin(float *input,int length){
    int minofmat = input[0];
    Matlabindex = 0;
    for (int i = 1; i < length; i++) {
        if(minofmat > input[i]){
            minofmat = input[i];
            Matlabindex = i;
        }
    }
    return minofmat;
}
int Matmin(int *input,int length){
    int minofmat = input[0];
    Matlabindex = 0;
    for (int i = 1; i < length; i++) {
        if(minofmat > input[i]){
            minofmat = input[i];
            Matlabindex = i;
        }
    }
    return minofmat;
}
int *cumsum(int *input, int length)
{
//    int *returnmatix;
//    returnmatix = new int(length);
    int *returnmatix = new int(length);
    for (int i = 0; i < length; i++) {
        if (i == 0) {
            returnmatix[0] = input[0];
        }
        else{
            returnmatix[i] = input[i] + input[i-1];
        }
    }
    return returnmatix;
}
int *Matsort(int *input, int length,int mode)
{
    int Subscript[length];
    MatlabindexSub = new int(length);
    for (int i = 0; i < length; i++) {
        Subscript[i] = i;
    }
    switch (mode) {
        case 0:
            for (int i = 0; i < length - 1; i++) {
                for (int j = 0; j < length - i - 1; j++) {
                    if (input[j] > input[j + 1]) {
                        int temp = input[j];
                        input[j] = input[j + 1];
                        input[j + 1] = temp;
                        
                        int tempSub = Subscript[j];
                        Subscript[j] = Subscript[j + 1];
                        Subscript[j + 1] = tempSub;
                    }
                }
            }
            break;
        case 1:
            for (int i = 0; i < length - 1; i++) {
                for (int j = 0; j < length - i - 1; j++) {
                    if (input[j] < input[j + 1]) {
                        int temp = input[j];
                        input[j] = input[j + 1];
                        input[j + 1] = temp;
                        
                        int tempSub = Subscript[j];
                        Subscript[j] = Subscript[j + 1];
                        Subscript[j + 1] = tempSub;
                    }
                }
            }
        default:
            break;
    }
    MatlabindexSub = Subscript;
    return input;
}
float *Matsort(float *input, int length,int mode)
{
    int Subscript[length];
    MatlabindexSub = new int(length);
    for (int i = 0; i < length; i++) {
        Subscript[i] = i;
    }
    switch (mode) {
        case 0:
            for (int i = 0; i < length - 1; i++) {
                for (int j = 0; j < length - i - 1; j++) {
                    if (input[j] > input[j + 1]) {
                        int temp = input[j];
                        input[j] = input[j + 1];
                        input[j + 1] = temp;
                        
                        int tempSub = Subscript[j];
                        Subscript[j] = Subscript[j + 1];
                        Subscript[j + 1] = tempSub;
                    }
                }
            }
            break;
        case 1:
            for (int i = 0; i < length - 1; i++) {
                for (int j = 0; j < length - i - 1; j++) {
                    if (input[j] < input[j + 1]) {
                        int temp = input[j];
                        input[j] = input[j + 1];
                        input[j + 1] = temp;
                        
                        int tempSub = Subscript[j];
                        Subscript[j] = Subscript[j + 1];
                        Subscript[j + 1] = tempSub;
                    }
                }
            }
        default:
            break;
    }
    MatlabindexSub = Subscript;
    return input;
}
