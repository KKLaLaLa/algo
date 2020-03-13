//
//  main.cpp
//  GA
//
//  Created by 王昆 on 2020/2/28.
//  Copyright © 2020 昆. All rights reserved.
//
#include <iostream>
#include "Genetic.hpp"
/*
f(x1,x2) = 21.5+x1*sin(4pi*x1)+x2*sin(20pi*x2)
st：x1:[-3.0,12.1]  x2:[4.1,5.8]
求函数在约束范围内的最大值
*/
extern Individual Population[GROUP_SCALE + 1];

int main()
{
    int Xnration;
    int i;
    int seed = 123456789;

    showTime();
    initGroup(seed); //随机初始化参数，初始化种群
    evaluate(); //计算适应度
    selectBest();  //挑选出适应函数最大的种群并存放

    for (Xnration = 0; Xnration < MAX_GENS; Xnration++) //开始迭代
    {
        selector(seed); //选择优秀的个体，使用轮盘法，产生下一代
        crossover(seed);
        mutate(seed);
        report(Xnration);  //输出每一代的均值和方差
        evaluate();  //再次计算适应度
        elitist();  //评估挑选最优的一代，将最差的一代剔除
    }

    cout << "\n";
    cout << "  Best member after " << MAX_GENS << " Xnrations:\n";
    cout << "\n";

    for (i = 0; i < N_VARS; i++)
    {
        cout << "  X(" << i + 1 << ") = " << Population[GROUP_SCALE].Xn[i] << "\n";
    }
    cout << "\n";
    cout << "  Best Fitness = " << Population[GROUP_SCALE].Fitness << "\n";

    showTime();
    //while (1);
    return 0;
}
