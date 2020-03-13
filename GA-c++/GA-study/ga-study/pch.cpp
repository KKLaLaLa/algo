//
//  pch.cpp
//  ga-study
//
//  Created by 王昆 on 2020/3/11.
//  Copyright © 2020 昆. All rights reserved.
//

#include "pch.hpp"
//*******************
//交叉算子函数，两点交叉
//*******************
void ga::crossover_operator(Individual population[N_genetic], vector<double> low, vector<double> high)
{
    int i, j, cpoint1, cpoint2, t;                //交叉点cpoint1, cpoint2生成,t为替换值
    double p_c;                              //随机产生交叉概率
    extern RandomNumber r;       //定义全局随机数
    extern ga GA;               //定义全局遗传算法相关函数
    for (i = 0; i < N_genetic; i = i + 2)
    {//随机产生两个交叉点的数
        cpoint1 = r.integer(0, 1000) % (N_variable* L_variable);
        cpoint2 = r.integer(0, 1000) % (N_variable* L_variable);
        if (cpoint2 < cpoint1)
        {
            t = cpoint2; cpoint2 = cpoint1; cpoint1 = t;
        }
        p_c = r.decimal(0, 1.0);
        //交叉过程
        if (p_c < C_pgentic)
        {
            for (j = cpoint1; j <= cpoint2; j++)
            {
                t = population[i].x_binary[j]; population[i].x_binary[j] = population[i + 1].x_binary[j]; population[i + 1].x_binary[j] = t;
            }
        }
    }
    //p_c = p(a); cout << p_c << endl;
    //交叉后的染色转换为实数
    for (i = 0; i < N_genetic; i++)
    {
        GA.Real_trans(population, &i, low, high);
    }
}
//*******************
//适应度函数，或目标函数
//*******************
double ga::fitness_function(vector<double>x)
{
    double fx=0;
    fx = ((cos(x[0]*x[0] + x[1] * x[1]) - 0.8) / (3 + 0.8*(x[0]*x[0] + x[1] * x[1])*(x[0]*x[0] + x[1] * x[1])) + 8);
    //fx = 0.5 + (pow(sin(x[0]*x[0] + x[1] *x[1]), 2) - 0.5) / pow(1 + 0.001*(x[0]*x[0] + x[1] *x[1]), 2);
    //fx = 11 * (x[0]*x[0] - x[1])*(x[0]*x[0] - x[1]) - (1 - x[1])*(1 - x[1]) + 2 * (1 + x[1])*(1 + x[1]) + 0.7;
    //第四个函数
    /*for (int i = 0; i < 10; i++)
    {
        fx = fx + x[i] * x[i] + 2 * x[i] - 3;
    }*/
    //第五个函数
    //fx = 11 * sin(7 * x[0]) + 7 * cos(3 * x[0]);
    //第6个函数
    //fx = x[0] * sin(8 * x[0]) + 3;
    return  fx;
}
//*******************
//初始化并赋值
//*******************
void ga::initialize(Individual *population, Individual *best_population)
{
    int i, j, random_gen;  //random_gen为基因随机值
    extern ga GA;          //定义全局遗传算法相关函数
    for (i = 0; i < N_genetic; i++)
    {
        population[i].x_i.resize(N_variable);
        population[i].x_decimal.resize(N_variable);
        population[i].x_binary.resize(N_variable*L_variable); //优化变量二进制
   //*******************
   //基因编码
   //*******************
        for (j = 0; j < N_variable*L_variable; j++)
        {
            random_gen = rand() % 2;
            population[i].x_binary[j] = random_gen;
        }
        GA.Real_trans(population, &i, GA.x_low, GA.x_high);
        //cout << population[i].x_i[0] << endl;
    }
    *best_population = population[0];                      //初始化最优个体
    GA.select_optimal(population, best_population);           //种群选优
}
//*******************
//变异算子函数，两点交叉
//*******************
void ga::mutate_operator(Individual population[N_genetic], vector<double> low, vector<double> high)
{
    int i,mpoint;//变异点mpoint生成
    double p_m;
    extern RandomNumber r;       //定义全局随机数
    extern ga GA;               //定义全局遗传算法相关函数
    for (i = 0; i < N_genetic; ++i)
    {//随机产生变异点
        mpoint = r.integer(0, 1000) % (N_variable* L_variable);
        p_m = r.decimal(0, 1.0);
        if (p_m < M_pgentic)
        {
            if (population[i].x_binary[mpoint] == 0)
            {
                population[i].x_binary[mpoint] = 1;
            }
            else {
                population[i].x_binary[mpoint] = 0;
            }
        }
    }
    //变异后的染色转换为实数
    for (i = 0; i < N_genetic; i++)
    {
        GA.Real_trans(population, &i, low, high);
        //cout << population[i].x_i[0] <<"、"<< population[i].x_i[1]<< endl;
    }
}
//***************************
//二进制转换为实数
//******************************
void ga::Real_trans(Individual *population, int *i_st, vector<double> low, vector<double> high)
{
    int j;
    for (j = 0; j < N_variable; j++)
    {
        population[*i_st].x_decimal[j] = 0;
        for (int k = j * L_variable, l_gen = 0; k < (j + 1)*L_variable; k++, l_gen++)
        {
            population[*i_st].x_decimal[j] = population[*i_st].x_decimal[j] + population[*i_st].x_binary[k] * pow(2, L_variable - l_gen);
        }
        population[*i_st].x_i[j] = low[j] + population[*i_st].x_decimal[j] / (pow(2, L_variable + 1) - 1)*(high[j] - low[j]);
    }
    population[*i_st].fitness = fitness_function(population[*i_st].x_i);    //计算个体适应度
}
//*******************
//选择算子函数
//*******************
void ga::select_operator(Individual population[N_genetic])
{
    int i, j;
    double totalfit = 0, p_i;
    extern RandomNumber r;       //随机数
    Individual new_population[E_gentic];        //储存选择产生的新个体
    for (i = 0; i < N_genetic; i++)
    {
        population[i].sumfitness = totalfit + population[i].fitness;
        totalfit = totalfit + population[i].fitness;
    }
    //计算个体概率
    for (i = 0; i < N_genetic; i++)
    {
        population[i].P_i = population[i].sumfitness / totalfit;
    }
    //选择父代
    for (i = 0; i <N_genetic; i++)
    {
        p_i = r.decimal(0,1.0);
        //利用轮盘法选择个体
        if (p_i <= population[0].P_i)
            new_population[i] = population[0];
        else
        {
            for (j = 0; j < N_genetic - 1; j++)
            {
                if (p_i > population[j].P_i&&p_i <= population[j + 1].P_i)
                    new_population[i] = population[j + 1];
            }
        }
    }
    //更新个体
    for (i = 0; i < N_genetic; i++)
    {
        population[i] = new_population[i];
    }
}
//*******************
//种群选优选择最大值或者最小值
//*******************
void ga::select_optimal(Individual population[N_genetic], Individual *best_population)
{
    for (int i = 0; i < N_genetic; i++)
    {
        if ((*best_population).fitness <population[i].fitness)
        {
            *best_population = population[i];
    }
    }
}



