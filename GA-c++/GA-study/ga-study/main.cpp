//
//  main.cpp
//  ga-study
//
//  Created by 王昆 on 2020/3/11.
//  Copyright © 2020 昆. All rights reserved.
//

#include "pch.hpp"
#include <iostream>
RandomNumber r;       //随机数
ga GA;  //定义遗传算法计算中相关函数以及变量上下值
int main()
{
    clock_t startTime, endTime; //定义程序开始运行时间和结束时间
    startTime = clock();        //计时开始
    Individual best_population;  //最好的个体
    //初始化并赋值0
    Individual *population = new Individual[N_genetic];
    GA.initialize(population, &best_population);
    //********************
    //开始迭代
    //*******************
    ofstream out("output.txt");
    for (int i = 0; i <= E_gentic; i++)
    {
        GA.select_operator(population);  //选择父代更新个体
        GA.crossover_operator(population, GA.x_low, GA.x_high);  //有交配权的所有父代进行交叉
        GA.mutate_operator(population, GA.x_low, GA.x_high);     //个体变异
        GA.select_optimal(population, &best_population);    //种群选优
    cout <<i<< fixed << setw(12) << setprecision(5) <<best_population.fitness<<endl;
    }
    cout << "最优变量:" << endl;
    for (int ii = 0; ii < N_variable; ii++)
    {
        cout << "x" << ii << "=" << fixed << setw(12) << setprecision(5) << best_population.x_i[ii] << endl;//输出最优变量
    }
    cout << "最优值=" << fixed << setw(12) << setprecision(5) << best_population.fitness << endl;
    endTime = clock();//计时结束
    cout << "run time:" << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    out.close();
}

