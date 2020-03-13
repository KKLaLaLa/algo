//
//  pch.hpp
//  ga-study
//
//  Created by 王昆 on 2020/3/11.
//  Copyright © 2020 昆. All rights reserved.
//

#ifndef pch_hpp
#define pch_hpp

#include <stdio.h>


#include <iostream>
# include <fstream>
#include <iomanip>
#include <math.h>
#include <cstdlib> // 标准库
#include <ctime> // 时间库
#include <vector> //容器头文件
#include<random>
#define N_genetic   50  //种群规模，太小产生病态基因；种群规模太大，难以收敛，一般0-100
#define M_pgentic   0.15//变异概率，与种群多样性有关，一般0.0001-0.2
#define C_pgentic   0.7   //交叉概率，概率太大，容易错失最优个体，太小布恩那个有效更新种群，一般0.4-0.99.
#define E_gentic   400  //进化代数，太小，算法不容易收敛，太大增加时间和资源浪费，一般100-500.
#define L_variable  8   //个体变量的字符串长度(基因数)
#define N_variable  2    //个体变量的个数
using namespace std;
//由于适应度函数要比较排序并在此基础计算选择概率，适应度函数的值应该取正值。
class Individual
{
public:
    vector<double>x_i;         //优化变量
    vector<double>x_decimal;    //优化变量十进制数
    vector<int>x_binary;      //个体染色体
    double fitness;          //个体适应度
    double sumfitness;       //前面个体适应度和
    double P_i;              //个体被选择的概率
};
//产生随机小数或整数
class RandomNumber {
public:
    RandomNumber() {
        srand((unsigned)time(NULL));    //析构函数，在对象创建时数据成员执行初始化操作
    }
    int integer(int begin , int end)
    {
        return rand() % (end - begin + 1) + begin;
    }
    double decimal(double a, double b)
    {
        return double(rand() % 10000) / 10000 * (b - a) + a;
    }
};
//ga用于定义优化变量范围，以及遗传算法过程中的选择、交叉、变异算子、解码、个体适应度计算等函数。
class ga
{
public:
    vector<double>x_low = {-10,-10};     //优化变量最小值
    vector<double>x_high = {10,10};     //优化变量最大值
    void initialize(Individual *population, Individual *best_population);//初始化，产生初始种群
    void Real_trans(Individual *population, int *i_st, vector<double> low, vector<double> high);   //二进制转换为实数
    double fitness_function(vector<double>x);//适应度计算函数
    void select_operator(Individual population[N_genetic]);//选择算子
    void select_optimal(Individual population[N_genetic], Individual *best_population);////选择最大值或者最小值
    void crossover_operator(Individual population[N_genetic], vector<double> low, vector<double> high);//交叉算子
    void mutate_operator(Individual population[N_genetic], vector<double> low, vector<double> high);//变异算子
};
#endif /* pch_hpp */
