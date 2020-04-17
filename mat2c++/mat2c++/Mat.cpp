//
//  Mat.cpp
//  mat2c++
//
//  Created by 王昆 on 2020/4/10.
//  Copyright © 2020 昆. All rights reserved.
//

#include "Mat.hpp"

int MatFunction::Matsum(vector<int> vec)
/*
 输入：需要操作的向量
 操作：将里面的值求和
 输出：整型的求和结果
 */
{
    //int num = vec.size();
    int sum =0;
    for (auto it = vec.begin(); it != vec.end(); it++) {
        sum += *it;
    }
    return sum;
}
double MatFunction::Matsum(vector<double> vec)
/*
输入：需要操作的向量
操作：将里面的值求和
输出：浮点型的求和结果
*/
{
    //int num = vec.size();
    double sum =0.0;
    for (auto it = vec.begin(); it != vec.end(); it++) {
        sum += *it;
    }
    return sum;
}

vector<vector<int>> MatFunction::Matarr2vec2(int *arr,int row, int col)
/*
 输入：二维数组及其行数和列数
 操作：转换为二维向量
 输出：转换后的二维向量
 */
{
    vector<vector<int>> return_vec2(row);
    for(int i = 0; i < row; i++)
    {
        return_vec2[i].resize(col);
    }
    int k = 0;
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            return_vec2[i][j] = *(arr + k);
            k++;
        }
    }
    return return_vec2;
}
vector<vector<double>> MatFunction::Matarr2vec2(double *arr,int row, int col)
{
    vector<vector<double>> return_vec2(row);
    for(int i = 0; i < row; i++)
    {
        return_vec2[i].resize(col);
    }
    int k = 0;
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            return_vec2[i][j] = *(arr + k);
            k++;
        }
    }
    return return_vec2;
}

vector<int> MatFunction::Matcumsum(vector<int> vec)
/*
输入：需要操作的向量
操作：进行累积和计算
输出：整型的结果，以向量形式返回
*/
{
    vector<int> return_vec(vec.size());
    auto len = vec.size();
    return_vec[0] = vec[0];
    for (int it = 1; it < len; it++) {
        return_vec[it] = vec[it] + vec[it-1];
    }
    return return_vec;
}

vector<double> MatFunction::Matcumsum(vector<double> vec)
/*
输入：需要操作的向量
操作：进行累积和计算
输出：浮点型的结果，以向量形式返回
*/
{
    vector<double> return_vec(vec.size());
    auto len = vec.size();
    return_vec[0] = vec[0];
    for (int it = 1; it < len; it++) {
        return_vec[it] = vec[it] + vec[it-1];
    }
    return return_vec;
}

vector<int> MatFunction::Matfind(vector<int> vec,int compval,string input)
/*
输入：需要操作的向量，比较的值，哪种操作
操作：提供>,>=,<,<=四种操作，将输入向量中>,>=,<,<=compval的值，存放到返回的向量中
输出：整型的结果，以向量形式返回
*/
{
    vector<int> return_vec(vec.size());
    auto vec_len = vec.size();
    int add = 0;
    if(input == ">")
    {
        for (int i = 0; i < vec_len; i++) {
            if (vec[i] > compval) {
                return_vec[add] = i;
                add++;
            }
        }
        return_vec.resize(add);
    }
    if(input == ">=")
    {
        for (int i = 0; i < vec_len; i++) {
            if (vec[i] >= compval) {
                return_vec[add] = i;
                add++;
            }
        }
        return_vec.resize(add);
    }
    if(input == "<")
    {
        for (int i = 0; i < vec_len; i++) {
            if (vec[i] < compval) {
                return_vec[add] = i;
                add++;
            }
        }
        return_vec.resize(add);
    }
    if(input == "<=")
    {
        for (int i = 0; i < vec_len; i++) {
            if (vec[i] <= compval) {
                return_vec[add] = i;
                add++;
            }
        }
        return_vec.resize(add);
    }
    return return_vec;
}

vector<int> MatFunction::Matfind(vector<double> vec,double compval,string input)
/*
输入：需要操作的向量，比较的值，哪种操作
操作：提供>,>=,<,<=四种操作，将输入向量中>,>=,<,<=compval的值，存放到返回的向量中
输出：浮点型的结果，以向量形式返回
*/
{
    vector<int> return_vec(vec.size());
    auto vec_len = vec.size();
    int add = 0;
    if(input == ">")
    {
        for (int i = 0; i < vec_len; i++) {
            if (vec[i] > compval) {
                return_vec[add] = i;
                add++;
            }
        }
        return_vec.resize(add);
    }
    if(input == ">=")
    {
        for (int i = 0; i < vec_len; i++) {
            if (vec[i] >= compval) {
                return_vec[add] = i;
                add++;
            }
        }
        return_vec.resize(add);
    }
    if(input == "<")
    {
        for (int i = 0; i < vec_len; i++) {
            if (vec[i] < compval) {
                return_vec[add] = i;
                add++;
            }
        }
        return_vec.resize(add);
    }
    if(input == "<=")
    {
        for (int i = 0; i < vec_len; i++) {
            if (vec[i] <= compval) {
                return_vec[add] = i;
                add++;
            }
        }
        return_vec.resize(add);
    }
    return return_vec;
}

pair<int, int> MatFunction::Matmax(vector<int> vec)
/*
输入：需要操作的向量
操作：找寻最大的元素和对应的下标
输出：最大整型元素和下标，以pair类型返回
*/
{
    auto vec_len = vec.size();
    int maxval,maxvali;
    maxval = vec[0];
    maxvali = 0;
    for (int i = 1; i < vec_len; i++) {
        if ( vec[i] > maxval ) {
            maxval = vec[i];
            maxvali = i;
        }
    }
    return make_pair(maxval, maxvali);
}
pair<double, int> MatFunction::Matmax(vector<double> vec)
/*
输入：需要操作的向量
操作：找寻最大的元素和对应的下标
输出：最大浮点型元素和下标，以pair类型返回
*/
{
    auto vec_len = vec.size();
    double maxval;
    int maxvali;
    maxval = vec[0];
    maxvali = 0;
    for (int i = 1; i < vec_len; i++) {
        if ( vec[i] > maxval ) {
            maxval = vec[i];
            maxvali = i;
        }
    }
    return make_pair(maxval, maxvali);
}

pair<int, int> MatFunction::Matmin(vector<int> vec)
/*
输入：需要操作的向量
操作：找寻最小的元素和对应的下标
输出：最小整型元素和下标，以pair类型返回
*/
{
    auto vec_len = vec.size();
    int minval,minvali;
    minval = vec[0];
    minvali = 0;
    for (int i = 1; i < vec_len; i++) {
        if ( vec[i] < minval ) {
            minval = vec[i];
            minvali = i;
        }
    }
    return make_pair(minval, minvali);
}
pair<double, int> MatFunction::Matmin(vector<double> vec)
/*
输入：需要操作的向量
操作：找寻最小的元素和对应的下标
输出：最小浮点型元素和下标，以pair类型返回
*/
{
    auto vec_len = vec.size();
    double minval;
    int minvali;
    minval = vec[0];
    minvali = 0;
    for (int i = 1; i < vec_len; i++) {
        if ( vec[i] < minval ) {
            minval = vec[i];
            minvali = i;
        }
    }
    return make_pair(minval, minvali);
}

pair<vector<int>, vector<int>> MatFunction::Matsort(vector<int> vec,string input)
/*
输入：需要操作的向量和需要操作的方式
操作：将输入的向量按照要求的方式进行排序，主要有max：从小到大，min：从大到小，两种方式
输出：返回排序结果和对应的原下标向量（操作整型向量）
*/
{
    vector<int> return_sort(vec);
    vector<int> return_sorti(vec.size());
    auto length = vec.size();
    for (int i = 0; i < length; i++) {
        return_sorti[i] = i;
    }
    if (input == "max") {
        for (int i = 0; i < length - 1; i++) {
            for (int j = 0; j < length - i - 1; j++) {
                if (return_sort[j] > return_sort[j + 1]) {
                    int temp = return_sort[j];
                    return_sort[j] = return_sort[j + 1];
                    return_sort[j + 1] = temp;
                
                    int tempSub = return_sorti[j];
                    return_sorti[j] = return_sorti[j + 1];
                    return_sorti[j + 1] = tempSub;
                }
            }
        }
    }
    if (input == "min") {
        for (int i = 0; i < length - 1; i++) {
            for (int j = 0; j < length - i - 1; j++) {
                if (return_sort[j] < return_sort[j + 1]) {
                    int temp = return_sort[j];
                    return_sort[j] = return_sort[j + 1];
                    return_sort[j + 1] = temp;
                
                    int tempSub = return_sorti[j];
                    return_sorti[j] = return_sorti[j + 1];
                    return_sorti[j + 1] = tempSub;
                }
            }
        }
    }
    
    return make_pair(return_sort, return_sorti);
}
pair<vector<double>, vector<int>> MatFunction::Matsort(vector<double> vec,string input)
/*
输入：需要操作的向量和需要操作的方式
操作：将输入的向量按照要求的方式进行排序，主要有max：从小到大，min：从大到小，两种方式
输出：返回排序结果和对应的原下标向量（操作浮点型向量）
*/
{
    vector<double> return_sort(vec);
    vector<int> return_sorti(vec.size());
    auto length = vec.size();
    for (int i = 0; i < length; i++) {
        return_sorti[i] = i;
    }
    if (input == "max") {
        for (int i = 0; i < length - 1; i++) {
            for (int j = 0; j < length - i - 1; j++) {
                if (return_sort[j] > return_sort[j + 1]) {
                    double temp = return_sort[j];
                    return_sort[j] = return_sort[j + 1];
                    return_sort[j + 1] = temp;
                
                    int tempSub = return_sorti[j];
                    return_sorti[j] = return_sorti[j + 1];
                    return_sorti[j + 1] = tempSub;
                }
            }
        }
    }
    if (input == "min") {
        for (int i = 0; i < length - 1; i++) {
            for (int j = 0; j < length - i - 1; j++) {
                if (return_sort[j] < return_sort[j + 1]) {
                    double temp = return_sort[j];
                    return_sort[j] = return_sort[j + 1];
                    return_sort[j + 1] = temp;
                
                    int tempSub = return_sorti[j];
                    return_sorti[j] = return_sorti[j + 1];
                    return_sorti[j + 1] = tempSub;
                }
            }
        }
    }
    
    return make_pair(return_sort, return_sorti);
}

vector<int> MatFunction::Matextract_row(vector<vector<int>> vec2,int ext_row)
/*
 输入：输入需要提取的二维向量
 操作：提取出指定的行
 输出：该行的数据
 */
{
    vector<int> return_vec(vec2[0].size());
    for(int j = 0; j < vec2[0].size(); j++)
    {
        return_vec[j] = vec2[ext_row][j];
    }
    return return_vec;
}
vector<double> MatFunction::Matextract_row(vector<vector<double>> vec2,int ext_row)
{
    vector<double> return_vec(vec2[0].size());
    for(int j = 0; j < vec2[0].size(); j++)
    {
        return_vec[j] = vec2[ext_row][j];
    }
    return return_vec;
}
vector<int> MatFunction::Matextract_col(vector<vector<int>> vec2, int ext_col)
/*
输入：输入需要提取的二维向量
操作：提取出指定的列
输出：该列的数据
*/
{
    vector<int> return_vec(vec2.size());
    for(int j = 0; j < vec2.size(); j++)
    {
        return_vec[j] = vec2[j][ext_col];
    }
    return return_vec;
}
vector<double> MatFunction::Matextract_col(vector<vector<double>> vec2, int ext_col)
{
    vector<double> return_vec;
    for(int j = 0; j < vec2.size(); j++)
    {
        return_vec[j] = vec2[j][ext_col];
    }
    return return_vec;
}

vector<int> MatFunction::Matrowset(vector<int> vec,int start,int end,int set_value)
/*
 输入：输入需要操作的向量，位置和数据
 操作：将指定连续位置设置set_value
 输出：操作后的向量
 */
{
    vector<int> return_vec(vec);
    for(int i = start;i < end; i++)
    {
        return_vec[i] = set_value;
    }
    return return_vec;
}
vector<double> MatFunction::Matrowset(vector<double> vec,int start,int end,double set_value)
{
    vector<double> return_vec(vec);
    for(int i = start;i < end; i++)
    {
        return_vec[i] = set_value;
    }
    return return_vec;
}

vector<int> MatFunction::Matopera(vector<int> vec,int opevalue,string operate)
/*
输入：输入需要操作的向量，数据和操作
操作：将向量进行操作
输出：操作后的向量
*/
{
    vector<int> return_vec;
    //vector<int> return_vec_d;
    if (operate == "+") {
        for (int i = 0; i < vec.size(); i++) {
            return_vec[i] = vec[i] + opevalue;
        }
    }
    if (operate == "-") {
        for (int i = 0; i < vec.size(); i++) {
            return_vec[i] = vec[i] - opevalue;
        }
    }
    if (operate == "*") {
        for (int i = 0; i < vec.size(); i++) {
            return_vec[i] = vec[i] * opevalue;
        }
    }
    if (operate == "/") {
        for (int i = 0; i < vec.size(); i++) {
            return_vec[i] = vec[i] / opevalue;
        }
    }
    return return_vec;
}
vector<double> MatFunction::Matopera(vector<double> vec,double opevalue,string operate)
{
    vector<double> return_vec;
    if (operate == "+") {
        for (int i = 0; i < vec.size(); i++) {
            return_vec[i] = vec[i] + opevalue;
        }
    }
    if (operate == "-") {
        for (int i = 0; i < vec.size(); i++) {
            return_vec[i] = vec[i] - opevalue;
        }
    }
    if (operate == "*") {
        for (int i = 0; i < vec.size(); i++) {
            return_vec[i] = vec[i] * opevalue;
        }
    }
    if (operate == "/") {
        for (int i = 0; i < vec.size(); i++) {
            return_vec[i] = vec[i] / opevalue;
        }
    }
    return return_vec;
}


bool MatFunction::Matisempty(vector<int> vec)
/*
 输入：需要判断的向量
 操作：判断
 输出：true or false
 */
{
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] != 0) {
            return false;
        }
    }
    return true;
}
bool MatFunction::Matisempty(vector<double> vec)
{
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] != 0) {
            return false;
        }
    }
    return true;
}
