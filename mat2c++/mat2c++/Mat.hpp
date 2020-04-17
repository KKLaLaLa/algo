//
//  Mat.hpp
//  mat2c++
//
//  Created by 王昆 on 2020/4/10.
//  Copyright © 2020 昆. All rights reserved.
//

#ifndef Mat_hpp
#define Mat_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <ctime>
#include <array>

using namespace std;
class MatFunction
{
public:
    

    //求和
    //template <typename T> T Matsum(vector<T> vec);
    int Matsum(vector<int> vec);
    double Matsum(vector<double> vec);
    //二维数组转换为二维向量
    vector<vector<int>> Matarr2vec2(int *arr,int row, int col);
    vector<vector<double>> Matarr2vec2(double *arr,int row, int col);
    //累计和
    vector<int> Matcumsum(vector<int> vec);
    vector<double> Matcumsum(vector<double> vec);
    //寻找最值返回索引,提供>,>=,<,<=
    vector<int> Matfind(vector<int> vec,int compval,string input);
    vector<int> Matfind(vector<double> vec,double compval,string input);
    //寻找最大值返回元素和索引
    pair<int, int> Matmax(vector<int> vec);
    pair<double, int> Matmax(vector<double> vec);
    //寻找最小值返回元素和索引
    pair<int, int> Matmin(vector<int> vec);
    pair<double, int> Matmin(vector<double> vec);
    //排序，返回排序结果和索引
    pair<vector<int>, vector<int>> Matsort(vector<int> vec,string input);
    pair<vector<double>, vector<int>> Matsort(vector<double> vec,string input);
    //提取矩阵的行
    vector<int> Matextract_row(vector<vector<int>> vec2, int ext_row);
    vector<double> Matextract_row(vector<vector<double>> vec2, int ext_row);
    //提取矩阵的列
    vector<int> Matextract_col(vector<vector<int>> vec2, int ext_row);
    vector<double> Matextract_col(vector<vector<double>> vec2, int ext_row);
    //数组随机连续位置赋值
    vector<int> Matrowset(vector<int> vec,int start,int end,int set_value);
    vector<double> Matrowset(vector<double> vec,int start,int end,double set_value);
    //数据统一操作+-*/
    vector<int> Matopera(vector<int> vec,int opevalue,string operate);
    vector<double> Matopera(vector<double> vec,double opevalue,string operate);
    //判空函数
    bool Matisempty(vector<int> vec);
    bool Matisempty(vector<double> vec);
};

#endif /* Mat_hpp */
